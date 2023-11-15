/*
 * sd_card.c
 *
 *  Created on: 2022年3月10日
 *      Author: guoqiang.xiong
 */



#include "../inc/sd_card.h"
#include "../inc/spi.h"
#include <stdio.h>
//#include "spidrv.h"
//#include "sl_udelay.h"

uint8_t  SD_Type;

/*
 * 取消片选，释放SPI总线
 *
 * 参数：void
 * 返回值：void
 * */\
#define	SPI_CS_OFF   QSPI0_REG(SPI_REG_CSID)=0x0;
void SD_DisSelect(void)
{
//    SD_CS_SET_GPIO_OUTPUT_STATUS(1);//SD_CS=1;
    SPI_CS_OFF;
    SPI_WriteReadByte(0xff);//提供额外的8个时钟
}

/*
 * 等待SD卡准备好
 * 参数：void
 * 返回值：准备好了返回0  否则返回其他
 * */
uint8_t SD_WaitReady(void)
{
    uint32_t t=0;
    do
    {
        if(SPI_WriteReadByte(0XFF)==0XFF)return 0;//OK
        t++;
    }while(t<0XFF);//等待
    return 1;
}

/*
 * 选择SD卡，并且等待SD卡准备好
 * 参数：void
 * 返回值：0,成功;1,失败
 * */
uint8_t SD_Select(void)
{
//    SD_CS_SET_GPIO_OUTPUT_STATUS(0);//SD_CS=0;
	SPI_CS_ON;
    if(SD_WaitReady()==0)return 0;//等待成功
    SD_DisSelect();
    return 1;//等待失败
}

/*
 * 向SD卡发送一个命令
 * 参数: u8 cmd   命令
 *      u32 arg  命令参数
 *      u8 crc   crc校验值
 * 返回值：SD卡返回的响应
 * */
uint8_t SD_SendCmd(uint8_t cmd, uint32_t arg, uint8_t crc)
{
    uint8_t r1;
    uint8_t Retry=0;
    SD_DisSelect();//取消上次片选
    if(SD_Select())//return 0XFF;//片选失效
    	SPI_CS_ON;
    //发送
    SPI_WriteReadByte(cmd | 0x40);//分别写入命令
    SPI_WriteReadByte(arg >> 24);
    SPI_WriteReadByte(arg >> 16);
    SPI_WriteReadByte(arg >> 8);
    SPI_WriteReadByte(arg);
    SPI_WriteReadByte(crc);
    if(cmd==CMD12)SPI_WriteReadByte(0xff);//Skip a stuff byte when stop reading
    //等待响应，或超时退出
    Retry=0X1F;
    do
    {
        r1=SPI_WriteReadByte(0xFF);
    }while((r1&0X80) && Retry--);
    //返回状态值
    return r1;
}

/*
 * 等待SD卡回应
 * 参数：Response:要得到的回应值
 * 返回值：0,成功得到了该回应值
 *      其他,得到回应值失败
 * */
uint8_t SD_GetResponse(uint8_t Response)
{
    uint16_t Count=0xFFFF;//等待次数
    while ((SPI_WriteReadByte(0XFF)!=Response)&&Count)Count--;//等待得到准确的回应
    if (Count==0)return 1;//得到回应失败
    else return 0;//正确回应
}

/*
 * 从sd卡读取一个数据包的内容
 * 参数：buf:数据缓存区
 *      len:要读取的数据长度.
 * 返回值:0,成功;其他,失败;
 * */
uint8_t SD_RecvData(uint8_t*buf,uint16_t len)
{
    if(SD_GetResponse(0xFE))return 1;//等待SD卡发回数据起始令牌0xFE
    while(len--)//开始接收数据
    {
        *buf=SPI_WriteReadByte(0xFF);
        buf++;
    }
    //下面是2个伪CRC（dummy CRC）
    SPI_WriteReadByte(0xFF);
    SPI_WriteReadByte(0xFF);
    return 0;//读取成功
}

/*
 * 获取SD卡的CID信息，包括制造商信息
 * 参数：u8 *cid_data(存放CID的内存，至少16Byte）
 * 返回值：0：NO_ERR   1：错误
 * */
uint8_t SD_GetCID(uint8_t *cid_data)
{
    uint8_t r1;
    //发CMD10命令，读CID
    r1=SD_SendCmd(CMD10,0,0x01);
    if(r1==0x00)
    {
        r1=SD_RecvData(cid_data,16);//接收16个字节的数据
    }
    SD_DisSelect();//取消片选
    if(r1)return 1;
    else return 0;
}

/*
 * 获取SD卡的CSD信息，包括容量和速度信息
 * 参数:u8 *cid_data(存放CID的内存，至少16Byte）
 *
 * 返回值:0：NO_ERR
 *      1：错误
 * */
uint8_t SD_GetCSD(uint8_t *csd_data)
{
    uint8_t r1;
    r1=SD_SendCmd(CMD9,0,0x01);//发CMD9命令，读CSD
    if(r1==0)
    {
        r1=SD_RecvData(csd_data, 16);//接收16个字节的数据
    }
    SD_DisSelect();//取消片选
    if(r1)return 1;
    else return 0;
}

/*
 * 获取SD卡的总扇区数（扇区数）
 *
 * 参数：void
 *
 * 返回值:0： 取容量出错
 *          其他:SD卡的容量(扇区数/512字节)
 * 每扇区的字节数必为512，因为如果不是512，则初始化不能通过.
 */
uint32_t SD_GetSectorCount(void)
{
    uint8_t csd[16];
    uint32_t Capacity;
    uint8_t n;
    uint16_t csize;
    //取CSD信息，如果期间出错，返回0
    if(SD_GetCSD(csd)!=0) return 0;
    //如果为SDHC卡，按照下面方式计算
    if((csd[0]&0xC0)==0x40)  //V2.00的卡
    {
        csize = csd[9] + ((uint16_t)csd[8] << 8) + 1;
        Capacity = (uint32_t)csize << 10;//得到扇区数
    }else//V1.XX的卡
    {
        n = (csd[5] & 15) + ((csd[10] & 128) >> 7) + ((csd[9] & 3) << 1) + 2;
        csize = (csd[8] >> 6) + ((uint16_t)csd[7] << 2) + ((uint16_t)(csd[6] & 3) << 10) + 1;
        Capacity= (uint32_t)csize << (n - 9);//得到扇区数
    }
    return Capacity;
}


/*
 * SD卡初始化
 *
 * 参数：void
 *
 * 返回值：初始化成功返回0
 *      失败返回其他
 * */
uint8_t SD_Init(void)
{
    uint8_t r1;      // 存放SD卡的返回值
    uint16_t retry;  // 用来进行超时计数
    uint8_t buf[4];
    uint16_t i;

    SPI_Init();
    for(i=0;i<20;i++)SPI_WriteReadByte(0XFF);//发送最少74个脉冲
    retry=20;
    do
    {
        r1=SD_SendCmd(CMD0,0,0x95);//进入IDLE状态
    }while((r1!=0X01) && retry--);
    SD_Type=0;//默认无卡
    if(r1==0X01)
    {
//        printf("SD_SendCmd(CMD0,0,0x95) SUCCESS!\r\n");
        if(SD_SendCmd(CMD8,0x1AA,0x87)==1)//SD V2.0
        {
            for(i=0;i<4;i++)buf[i]=SPI_WriteReadByte(0XFF);  //Get trailing return value of R7 resp
            if(buf[2]==0X01&&buf[3]==0XAA)//卡是否支持2.7~3.6V
            {
                retry=0XFFFE;
                do
                {
                    SD_SendCmd(CMD55,0,0X01);   //发送CMD55
                    r1=SD_SendCmd(CMD41,0x40000000,0X01);//发送CMD41
                }while(r1&&retry--);
                if(retry&&SD_SendCmd(CMD58,0,0X01)==0)//鉴别SD2.0卡版本开始
                {
//                    printf("SD_SendCmd(CMD41,0x40000000,0X01) SUCCESS!\r\n");
                    for(i=0;i<4;i++)buf[i]=SPI_WriteReadByte(0XFF);//得到OCR值
//                    for(int i = 0;i < 4;i++)
//                      {
//                        printf("buf[%d] %02X\r\n",i, buf[i]);
//                      }
                    if(buf[0]&0x40)SD_Type=SD_TYPE_V2HC;    //检查CCS
                    else SD_Type=SD_TYPE_V2;
//                    printf("SD_Type %02X\r\n", SD_Type);
                }
            }
        }
        else//SD V1.x/ MMC V3
        {
            SD_SendCmd(CMD55,0,0X01);       //发送CMD55
            r1=SD_SendCmd(CMD41,0,0X01);    //发送CMD41
            if(r1<=1)
            {
                SD_Type=SD_TYPE_V1;
                retry=0XFFFE;
                do //等待退出IDLE模式
                {
                    SD_SendCmd(CMD55,0,0X01);   //发送CMD55
                    r1=SD_SendCmd(CMD41,0,0X01);//发送CMD41
                }while(r1&&retry--);
            }else//MMC卡不支持CMD55+CMD41识别
            {
                SD_Type=SD_TYPE_MMC;//MMC V3
                retry=0XFFFE;
                do //等待退出IDLE模式
                {
                    r1=SD_SendCmd(CMD1,0,0X01);//发送CMD1
                }while(r1&&retry--);
            }
            if(retry==0||SD_SendCmd(CMD16,512,0X01)!=0)SD_Type=SD_TYPE_ERR;//错误的卡
        }
    }
    SD_DisSelect();//取消片选
    if(SD_Type)return 0;
    else if(r1)return r1;
    return 0xaa;//其他错误
}

/*
 * 向sd卡写入一个数据包的内容 512字节
 * 参数：buf:数据缓存区    cmd:指令
 * 返回值：0,成功;其他,失败;
 * */
uint8_t SD_SendBlock(uint8_t*buf,uint8_t cmd)
{
    uint16_t t;
    if(SD_WaitReady())return 1;//等待准备失效
    SPI_WriteReadByte(cmd);
    if(cmd!=0XFD)//不是结束指令
    {
        for(t=0;t<512;t++)SPI_WriteReadByte(buf[t]);//提高速度,减少函数传参时间
        SPI_WriteReadByte(0xFF);//忽略crc
        SPI_WriteReadByte(0xFF);
        t=SPI_WriteReadByte(0xFF);//接收响应
        if((t&0x1F)!=0x05)return 2;//响应错误
    }
    return 0;//写入成功
}

/*
 * 读SD卡
 * 参数：buf:数据缓存区
 *      sector:扇区
 *      cnt:扇区数
 * 返回值：0,ok;其他,失败.
 * */
uint8_t SD_ReadDisk(uint8_t*buf,uint32_t sector,uint8_t cnt)
{
    uint8_t r1;
    if(SD_Type!=SD_TYPE_V2HC)sector <<= 9;//转换为字节地址
    if(cnt==1)
    {
        r1=SD_SendCmd(CMD17,sector,0X01);//读命令
        if(r1==0)//指令发送成功
        {
            r1=SD_RecvData(buf,512);//接收512个字节
        }
    }else
    {
        r1=SD_SendCmd(CMD18,sector,0X01);//连续读命令
        do
        {
            r1=SD_RecvData(buf,512);//接收512个字节
            buf+=512;
        }while(--cnt && r1==0);
        SD_SendCmd(CMD12,0,0X01);   //发送停止命令
    }
    SD_DisSelect();//取消片选
    return r1;//
}

/*
 * 写SD卡
 * 参数：buf:数据缓存区
 *      sector:扇区
 *      cnt:扇区数
 * 返回值：0,ok;其他,失败.
 * */
uint8_t SD_WriteDisk(uint8_t*buf,uint32_t sector,uint8_t cnt)
{
    uint8_t r1;
    uint8_t reply = 200;
    if(SD_Type!=SD_TYPE_V2HC)sector *= 512;//转换为字节地址
    if(cnt==1)
    {
        r1=SD_SendCmd(CMD24,sector,0X01);//读命令
        if(r1==0)//指令发送成功
        {
            r1=SD_SendBlock(buf,0xFE);//写512个字节
        }
    }
    else
    {
        if(SD_Type!=SD_TYPE_MMC)
        {
            do
            {
                SD_SendCmd(CMD55,0,0X01);
//            SD_SendCmd(CMD23,cnt,0X01);//发送指令
               r1 = SD_SendCmd(CMD22,0x00,0X01);
            }while(r1 != 0x00 && reply--);
            for(int i = 0;i < 4;i++)SPI_WriteReadByte(0xff);

        }
        r1=SD_SendCmd(CMD25,sector,0X01);//连续读命令
        if(r1==0)
        {
            do
            {
                r1=SD_SendBlock(buf,0xFC);//接收512个字节
                buf+=512;
            }while(--cnt && r1==0);
            r1=SD_SendBlock(0,0xFD);//接收512个字节
        }
    }
    SD_DisSelect();//取消片选
    return r1;//
}

