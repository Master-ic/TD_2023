/*
 * spi.c
 *
 *  Created on: 2022年3月10日
 *      Author: guoqiang.xiong
 */



#include "../inc/spi.h"
#include "nuclei.h"
#include "nuclei_qspi.h"


//static void SPI_Delay(uint32_t us)
//{
////    sl_udelay_wait(us);
//}

#define SPI_SCKMODE_CPOL 1
#define SPI_SCKMODE_CPHA 0

#define SPI_MOSI_GPIO_OFFSET 27

#define SPI_SCK_GPIO_OFFSET 29


void SPI_Init(void)
{
//    CMU_ClockEnable(cmuClock_GPIO, true);  /* 使能GPIO时钟 */
//    GPIO_PinModeSet(SPI_CS_PORT, SPI_CS_PIN, gpioModePushPull, 0);
//    GPIO_PinModeSet(SPI_MOSI_PORT, SPI_MOSI_PIN, gpioModePushPull, 0);
//    GPIO_PinModeSet(SPI_CLK_PORT, SPI_CLK_PIN, gpioModePushPull, 0);
//
//    GPIO_PinModeSet(SPI_MISO_PORT, SPI_MISO_PIN, gpioModeInputPull, 0);
//
//    SD_CS_SET_GPIO_OUTPUT_STATUS(1);
//    SD_CLK_SET_GPIO_OUTPUT_STATUS(0);

	QSPI0_REG(SPI_REG_SCKMODE) &= ~((0x1 << SPI_SCKMODE_CPOL)|(0x1 << SPI_SCKMODE_CPHA));    // SCKMODE=00;
    QSPI0_REG(SPI_REG_FCTRL) &= ~(0x1<< 0);  //disable flash xip mode
    QSPI0_REG(SPI_REG_CSMODE) |= (0x1<< 1);  // hold mode
    QSPI0_REG(SPI_REG_SCKDIV)=0x07;  // SCK config: f_sck = f_clk / (2*(div+1)) = f_clk / 16;
//	SPI1_ReadWriteByte(0xff);
}

/*
* 函数名：void SPI_WriteByte(uint8_t data)
* 输入参数：data -> 要写的数据
* 输出参数：无
* 返回值：无
* 函数作用：模拟 SPI 写一个字节
*/
uint8_t SPI_WriteByte(uint8_t data)
{
//    uint8_t i = 0;
//    uint8_t temp = 0;
//    for(i=0; i<8; i++)
//    {
//        temp = ((data&0x80)==0x80)? 1:0;
//        data = data<<1;
//        SD_CLK_SET_GPIO_OUTPUT_STATUS(0); //SPI_CLK(0); //CPOL=0
//        SD_MOSI_SET_GPIO_OUTPUT_STATUS(temp);//SPI_MOSI(temp);
//        SPI_Delay(1);
//        SD_CLK_SET_GPIO_OUTPUT_STATUS(1);//SPI_CLK(1); //CPHA=0
//        SPI_Delay(1);
//    }
//    SD_CLK_SET_GPIO_OUTPUT_STATUS(0);//SPI_CLK(0);

    QSPI_TXDATA(QSPI0)=data;
    while(QSPI_STATUS(QSPI0) & (1<<0));
    return QSPI_RXDATA(QSPI0) & 0xff;
}
/*
* 函数名：uint8_t SPI_ReadByte(void)
* 输入参数：
* 输出参数：无
* 返回值：读到的数据
* 函数作用：模拟 SPI 读一个字节
*/
uint8_t SPI_ReadByte(void)
{
//    uint8_t i = 0;
    uint8_t read_data;
//    for(i=0; i<8; i++)
//    {
//        read_data = read_data << 1;
//        SD_CLK_SET_GPIO_OUTPUT_STATUS(0);//SPI_CLK(0);
//        SPI_Delay(1);
//        SD_CLK_SET_GPIO_OUTPUT_STATUS(1);//SPI_CLK(1);
//        SPI_Delay(1);
//        if(GPIO_PinInGet(SPI_MISO_PORT, SPI_MISO_PIN)==1)
//        {
//            read_data = read_data + 1;
//        }
//    }
//    SD_CLK_SET_GPIO_OUTPUT_STATUS(0);//SPI_CLK(0);
    QSPI_TXDATA(QSPI0)=0xFF;
    while(QSPI_STATUS(QSPI0) & (1<<0));
    read_data = QSPI_RXDATA(QSPI0) & 0xff;

    return read_data;
}




/*
* 函数名：uint8_t SPI_WriteReadByte(uint8_t data)
* 输入参数：data -> 要写的一个字节数据
* 输出参数：无
* 返回值：读到的数据
* 函数作用：模拟 SPI 读写一个字节
*/
uint8_t SPI_WriteReadByte(uint8_t data)
{
//    uint8_t i = 0;
//    uint8_t temp = 0;
    uint8_t read_data;
//    for(i=0;i<8;i++)
//    {
//        temp = ((data&0x80)==0x80)? 1:0;
//        data = data<<1;
//        read_data = read_data<<1;
//        SD_CLK_SET_GPIO_OUTPUT_STATUS(0);//SPI_CLK(0);
//        SD_MOSI_SET_GPIO_OUTPUT_STATUS(temp);//SPI_MOSI(temp);
//        SPI_Delay(1);
//        SD_CLK_SET_GPIO_OUTPUT_STATUS(1);//SPI_CLK(1);
//        SPI_Delay(1);
//        if(GPIO_PinInGet(SPI_MISO_PORT, SPI_MISO_PIN)==1)
//        {
//            read_data = read_data + 1;
//        }
//    }
//    SD_CLK_SET_GPIO_OUTPUT_STATUS(0); //SPI_CLK(0);
    QSPI_TXDATA(QSPI0) = data;
    while(QSPI_STATUS(QSPI0) & (1<<0));
    read_data = QSPI_RXDATA(QSPI0) & 0xff;

    return read_data;
}

