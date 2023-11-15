/*
 * sd_card.h
 *
 *  Created on: 2022年3月10日
 *      Author: guoqiang.xiong
 */

#ifndef APPLICATION_INC_SD_CARD_H_
#define APPLICATION_INC_SD_CARD_H_



//#include "sl_spidrv.h"
//#include "em_gpio.h"
//#include "sl_spidrv_spiflash_config.h"
#include "spi.h"

// SD卡类型定义
#define SD_TYPE_ERR     0X00
#define SD_TYPE_MMC     0X01
#define SD_TYPE_V1      0X02
#define SD_TYPE_V2      0X04
#define SD_TYPE_V2HC    0X06

// SD卡指令表
#define CMD0    0       //卡复位
#define CMD1    1
#define CMD8    8       //命令8 ，SEND_IF_COND
#define CMD9    9       //命令9 ，读CSD数据
#define CMD10   10      //命令10，读CID数据
#define CMD12   12      //命令12，停止数据传输
#define CMD16   16      //命令16，设置SectorSize 应返回0x00
#define CMD17   17      //命令17，读sector
#define CMD18   18      //命令18，读Multi sector
#define CMD22   22
#define CMD23   23      //命令23，设置多sector写入前预先擦除N个block
#define CMD24   24      //命令24，写sector
#define CMD25   25      //命令25，写Multi sector
#define CMD41   41      //命令41，应返回0x00
#define CMD55   55      //命令55，应返回0x01
#define CMD58   58      //命令58，读OCR信息
#define CMD59   59      //命令59，使能/禁止CRC，应返回0x00



//数据写入回应字意义
extern uint8_t  SD_Type;         //SD卡的类型

uint8_t SD_WaitReady(void);
uint8_t SD_GetCID(uint8_t *cid_data);
uint8_t SD_GetResponse(uint8_t Response);
uint8_t SD_Init(void);
uint32_t SD_GetSectorCount(void);
uint8_t SD_ReadDisk(uint8_t*buf,uint32_t sector,uint8_t cnt);
uint8_t SD_WriteDisk(uint8_t*buf,uint32_t sector,uint8_t cnt);



#endif /* APPLICATION_INC_SD_CARD_H_ */
