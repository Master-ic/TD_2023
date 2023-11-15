/*
 * pl_register_control.h
 *
 *  Created on: 2022年3月15日
 *      Author: guoqiang.xiong
 */

#ifndef APPLICATION_INC_PL_REGISTER_CONTROL_H_
#define APPLICATION_INC_PL_REGISTER_CONTROL_H_

#include "nuclei.h"

#define AHB_REGISTER_BASE_ADDR 0x43000000

volatile uint32_t *PS_WR_PSRAM_EN    = AHB_REGISTER_BASE_ADDR;
volatile uint32_t *PL_VERSION        = AHB_REGISTER_BASE_ADDR + 0x4;
volatile uint32_t *SCREEN_DISPLAY_EN = AHB_REGISTER_BASE_ADDR + 0x8;
//uint32_t *IMAGE_COL_NUM     = AHB_REGISTER_BASE_ADDR + 0xc;
//uint32_t *MIXER_COL_START   = AHB_REGISTER_BASE_ADDR + 0x10;
//uint32_t *MIXER_COL_END     = AHB_REGISTER_BASE_ADDR + 0x14;
//uint32_t *MIXER_LINE_SATRT  = AHB_REGISTER_BASE_ADDR + 0x18;
//uint32_t *MIXER_LINE_EN     = AHB_REGISTER_BASE_ADDR + 0x1c;
volatile uint32_t *PL_GOAL_RST       = AHB_REGISTER_BASE_ADDR + 0x24;

#define ps_wr_psram_en    *PS_WR_PSRAM_EN
#define pl_version        *PL_VERSION
#define screen_display_en *SCREEN_DISPLAY_EN
//#define vo_image_col_num  *IMAGE_COL_NUM
//#define mixer_col_start   *MIXER_COL_START
//#define mixer_col_end     *MIXER_COL_END
//#define mixer_line_start  *MIXER_LINE_SATRT
//#define mixer_line_end    *MIXER_LINE_EN
#define pl_goal_rst       *PL_GOAL_RST

#endif /* APPLICATION_INC_PL_REGISTER_CONTROL_H_ */
