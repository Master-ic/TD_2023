/*
 * spi.h
 *
 *  Created on: 2022年3月10日
 *      Author: guoqiang.xiong
 */

#ifndef APPLICATION_INC_SPI_H_
#define APPLICATION_INC_SPI_H_


//#include "em_gpio.h"
//#include "em_cmu.h"
#include "nuclei_qspi.h"

//
//// USART0 TX on PC00
//#define SPI_MOSI_PORT               gpioPortC
//#define SPI_MOSI_PIN                1
//
//// USART0 RX on PC01
//#define SPI_MISO_PORT               gpioPortC
//#define SPI_MISO_PIN               3
//
//// USART0 CLK on PC02
//#define SPI_CLK_PORT              gpioPortC
//#define SPI_CLK_PIN               0
//
//// USART0 CS on PC03
//#define SPI_CS_PORT               gpioPortC
//#define SPI_CS_PIN                2
//
//#define SD_CS_SET_GPIO_OUTPUT_STATUS(status)        {if(status == 1)   GPIO_PinOutSet(SPI_CS_PORT, SPI_CS_PIN);\
//                                                    else if(status == 0)  GPIO_PinOutClear(SPI_CS_PORT, SPI_CS_PIN);}
//
//
//#define SD_CLK_SET_GPIO_OUTPUT_STATUS(status)        {if(status == 1)   GPIO_PinOutSet(SPI_CLK_PORT, SPI_CLK_PIN);\
//                                                    else if(status == 0)  GPIO_PinOutClear(SPI_CLK_PORT, SPI_CLK_PIN);}
//
//
//#define SD_MOSI_SET_GPIO_OUTPUT_STATUS(status)        {if(status == 1)   GPIO_PinOutSet(SPI_MOSI_PORT, SPI_MOSI_PIN);\
//                                                    else if(status == 0)  GPIO_PinOutClear(SPI_MOSI_PORT, SPI_MOSI_PIN);}

#define	SPI_CS_ON    QSPI0_REG(SPI_REG_CSID)=0x1;
#define	SPI_CS_OFF   QSPI0_REG(SPI_REG_CSID)=0x0;

void SPI_Init(void);
uint8_t SPI_WriteByte(uint8_t data);
uint8_t SPI_ReadByte(void);
uint8_t SPI_WriteReadByte(uint8_t data);

#endif /* APPLICATION_INC_SPI_H_ */
