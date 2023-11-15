/*
 * bmp_load.c
 *
 *  Created on: 2022年3月10日
 *      Author: guoqiang.xiong
 */

#include "../inc/bmp_load.h"
#include "../inc/ff.h"
#include "stdio.h"
//#include"main.h"
//#include "../inc/pl_register_control.h"

#define AHB_REGISTER_BASE_ADDR 0x43000000
//int16_t img_array_1[14][28];
volatile uint32_t *IMAGE_COL_NUM     = AHB_REGISTER_BASE_ADDR + 0xc;
volatile uint32_t *MIXER_COL_START   = AHB_REGISTER_BASE_ADDR + 0x10;
volatile uint32_t *MIXER_COL_END     = AHB_REGISTER_BASE_ADDR + 0x14;
volatile uint32_t *MIXER_LINE_SATRT  = AHB_REGISTER_BASE_ADDR + 0x18;
volatile uint32_t *MIXER_LINE_EN     = AHB_REGISTER_BASE_ADDR + 0x1c;
volatile uint32_t *VO_READ_ADDR      = AHB_REGISTER_BASE_ADDR + 0x20;

#define vo_image_col_num  *IMAGE_COL_NUM
#define mixer_col_start   *MIXER_COL_START
#define mixer_col_end     *MIXER_COL_END
#define mixer_line_start  *MIXER_LINE_SATRT
#define mixer_line_end    *MIXER_LINE_EN
#define vo_read_addr      *VO_READ_ADDR

static FATFS fatfs;

void mixer_config(int col_start,int col_end,int line_start,int line_end)
{
	mixer_col_start  = col_start;
	mixer_col_end    = col_end;
	mixer_line_start = line_start;
	mixer_line_end   = line_end;
}

void sd_init(void)
{
	FRESULT rc;

	rc = f_mount(&fatfs,"1:",1);  //挂载文件系统 ， "1:"就是挂载的设备号为1的设备

	if(rc)
		printf("Error:sd card initial failed,f_mount returned %d\r\n",rc);
	else
		printf("sd card initial successful!\r\n");
}


/*******************************************
函数名称        ：bmp_image_to_ddr
函数输入参数：
函数返回值    ：无
函数作用        ：
 ******************************************/
int bmp_image_to_ddr(char *filename,uint32_t ddr_base_addr)
{
    FIL f_bmp;
	FRESULT rc;
	UINT bw;
	uint32_t image_line_num;
	uint32_t image_col_num;
	uint16_t bit_per_pixel; ///每个像素的位数
	uint16_t rgb565_temp_low;
	uint16_t rgb565_temp_high;
	uint32_t display_ddr_final_addr;  ///一帧图像的最终地址
	uint32_t image_start_offset;      ///bmp图像开始的偏移字节数
	uint32_t psram_sector_cnt;

	unsigned char bmp_head_info[64];   ///存储bmp文件头信息
//	unsigned char image_line_data[7680]; ///最大一行的数据1920*4=7680
	unsigned char image_line_data[8]; ///两个像素，最大4*2=8
	unsigned char not_use_data;

	uint32_t *display_ddr_addr;




	/*************************************************** 打开bmp图片 ********************************************/

	rc = f_open(&f_bmp,filename,FA_OPEN_EXISTING | FA_READ);

	if(rc)
	{
		printf("error:bmp file open failed,f_open return %d \r\n",rc);
		return 1;
	}
	else
		printf("bmp file open successed!\r\n");




	/******************************************** 读取bmp头文件信息，长度为54byte *************************************/

	rc = f_read(&f_bmp,&bmp_head_info,54,&bw);

//	if(rc)
//	{
//		printf("error:bmp head information read failed,f_read return %d \r\n",rc);
//		//return 1;
//	}
//	else
//		printf("bmp head information read successful!\r\n");




	/********************************************* 根据读到的头文件信息来解析图片 ****************************************/
	/*位图文件头
	 * 0,1  : 42 4D为位图的标志，如果转换成ASCII码的话就是BM
	 * 2-5  : (D5,D4,D3,D2)H，          表示文件大小，单位为字节bytes
	 * 6-9  : (D9,D8,D7,D6)H，          保留字
	 * 10-13: (D13,D12,D11,D10)H，表示文件起始位置标志，图像数据是从第54位开始
	 *
	 * 位图信息头
	 * 14-17: (D17,D16,D15,D14)H，表示位图信息头的长度，一般长度为40bytes
	 * 18-21: (D21,D20,D19,D18)H，表示位图宽度，也就是图片的列数
	 * 22-25: (D25,D24,D23,D22)H，表示位图高度，也就是图片的行数，图片的存储方式为从最后一行先存，最后存第一行
	 * 26-27: (D27,D26)H，                    表示设备级别
	 * 28-29: (D29,D28)H，                    表示位图的色彩级别，如果为十进制为24，那么表示一个像素为24bit，rgb三个通道各8bit
	 * 30-33: (D33,D32,D31,D30)H，表示压缩类型，0表示不压缩
	 * 34-37: (D37,D36,D35,D34)H，表示图片数据的字节数，单位为字节bytes
	 * 38-41: (D41,D40,D39,D38)H，表示水平分辨率，一般不用
	 * 42-45: (D45,D44,D43,D42)H，表示垂直分辨率，一般不用
	 * 46-49: (D49,D48,D47,D46)H，表示位图实际使用的颜色表中的颜色变址
	 * 50-53: (D53,D52,D51,D50)H，表示位图显示过程中被认为重要颜色变址数
	 */

	//解析图像的行数和列数
	image_line_num = (bmp_head_info[25]<<24) + (bmp_head_info[24]<<16) + (bmp_head_info[23]<<8) + bmp_head_info[22];

	image_col_num  = (bmp_head_info[21]<<24) + (bmp_head_info[20]<<16) + (bmp_head_info[19]<<8) + bmp_head_info[18];


	vo_image_col_num = image_col_num;

	vo_read_addr     = (ddr_base_addr & 0x00ffffff) >> 1;

	//解析每个像素的位数
	bit_per_pixel  = (bmp_head_info[29]<<8) + bmp_head_info[28];




	//img_array_1[0][0]=0;
	printf("image line = %ld,image col = %ld,bit per pixel = %d\r\n",image_line_num,image_col_num,bit_per_pixel);

	image_start_offset = (bmp_head_info[13]<<24) + (bmp_head_info[12]<<16) + (bmp_head_info[11]<<8) + bmp_head_info[10];

	for(int i = 1; i <= image_start_offset-54; i++)
	{
		f_read(&f_bmp,not_use_data,1,&bw); ///中间无用数据取出
	}


//	image_start_offset = (bmp_head_info[13]<<24) + (bmp_head_info[12]<<16) + (bmp_head_info[11]<<8) + bmp_head_info[10];
//
//
//	for(int i = 1; i <= image_start_offset-54; i++)
//	{
//		f_read(&f_bmp,not_use_data,1,&bw); ///中间无用数据取出
//	}

	/************************************************ 将图片数据按行存入ddr中 *********************************************/
	/*
	 * bmp图像数据按照B G R顺序排列
	 */

	//display_ddr_final_addr = ddr_base_addr + ((image_line_num*image_col_num)/2);  ///计算一帧图像最终的地址，由于转换成rgb565，一个地址32bit数据存储两个像素，因此除2



	psram_sector_cnt = 0;

	unsigned char pic_data[1];
	pic_data[0]=1;
	int d=0;

//	f_read(&f_bmp,&pic_data,10,&bw);   ///每次从sd卡里面读出一个八位像素数据
//	f_read(&f_bmp,&image_line_data,6,&bw);

	for(int j = 1; j <= image_line_num; j++)
	{

		for(int k = 1; k <= image_col_num; k++)
		{


				f_read(&f_bmp,&pic_data,1,&bw);   ///每次从sd卡里面读出一个八位像素数据
				//f_read(&f_bmp,&image_line_data,6,&bw);   ///每次从sd卡里面读出两个24像素数据
				 printf("%d\n",pic_data[0]);
				 d=d+1;

		}


}
return 0;
}


