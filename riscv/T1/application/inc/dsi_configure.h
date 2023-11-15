/*
 * dsi_configure.h
 *
 *  Created on: 2022年3月4日
 *      Author: guoqiang.xiong
 */

#ifndef APPLICATION_INC_DSI_CONFIGURE_H_
#define APPLICATION_INC_DSI_CONFIGURE_H_


void dsi_0_configure(void);
void dsi_0_configure_read(void);
void dsi_1_configure(void);
void dsi_1_configure_read(void);

void dsi_0_dcs_data_write_np(uint8_t data);
void dsi_0_dcs_data_write_1p(uint8_t data0,uint8_t data1);
void dsi_0_dcs_data_write_3p(uint8_t data0,uint8_t data1,uint8_t data2,uint8_t data3);
void lcd_screen_config(void);

#endif /* APPLICATION_INC_DSI_CONFIGURE_H_ */
