/*
 * bmp_load.h
 *
 *  Created on: 2022年3月10日
 *      Author: guoqiang.xiong
 */

#ifndef APPLICATION_INC_BMP_LOAD_H_
#define APPLICATION_INC_BMP_LOAD_H_

#include "nuclei.h"


void mixer_config(int col_start,int col_end,int line_start,int line_end);
void sd_init(void);
int bmp_image_to_ddr(char *filename,uint32_t ddr_base_addr);



#endif /* APPLICATION_INC_BMP_LOAD_H_ */



extern int16_t img_array_1[14][28];
