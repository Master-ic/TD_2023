/*
 * oled_display.h
 *
 *  Created on: 2022年1月13日
 *      Author: guoqiang.xiong
 */

#ifndef APPLICATION_INC_OLED_DISPLAY_H_
#define APPLICATION_INC_OLED_DISPLAY_H_


void anlogic_log_display(void);
void display_horizontal_scroll_enable(void);
void display_horizontal_scroll_disable(void);
void OLED_Init(void);						// OLED 初始化
void OLED_Clear(void);						// OLED 清屏
void OLED_WriteCmd(int cmd);		// OLED 单次写命令
void OLED_WriteDat(int dat);		// OLED 单次写数据
void OLED_WriteC(int cmd);		// OLED 连续写命令	在结尾要加上IIC_STOP();
void OLED_WriteD(int dat);		// OLED 连续写数据	在结尾要加上IIC_STOP();
void OLED_Frame(int P[8][128]);	// OLED 一帧图像写入
void IIC_START(void);				// IIC_开始信号	(重开始信号用此替代)
void IIC_STOP(void); 				// IIC_结束信号
int IIC_WaitACK(void);		// IIC_等待应答		返回值: 0:NACK 1:ACK
void IIC_Write(int dat);	// IIC_写数据函数	参数:要写入的数据
int IIC_Read(void);		// IIC_读数据函数	返回值:读到的数据
void delay1us(void);					// 延时1us
void SCL_Low(void);
void SCL_High(void);
void SDA_Low(void);
void SDA_High(void);
int SDA_read(void);
void LED_High(void);
void LED_Low(void);
void oled_display_reset(void);

#endif /* APPLICATION_INC_OLED_DISPLAY_H_ */
