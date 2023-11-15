/*
 * gpio_controler.c
 *
 *  Created on: 2022年1月15日
 *      Author: guoqiang.xiong
 */


#include "./inc/gpio_controler.h"
#include "nuclei.h"


#define GPIO_BASE_ADDRESS 0xE0020000


volatile uint32_t *GPIO_IVAL = GPIO_BASE_ADDRESS + 0x00000000;
volatile uint32_t *GPIO_IEN  = GPIO_BASE_ADDRESS + 0x00000004;
volatile uint32_t *GPIO_OEN  = GPIO_BASE_ADDRESS + 0x00000008;
volatile uint32_t *GPIO_OVAL = GPIO_BASE_ADDRESS + 0x0000000c;


#define gpio_in     *GPIO_IVAL
#define gpio_in_en  *GPIO_IEN
#define gpio_out_en *GPIO_OEN
#define gpio_out    *GPIO_OVAL



void gpio_wr(int index,int wr_data)
{
	switch(index)
	{
		case 0:
				gpio_in_en  = gpio_in_en & 0xfffffffe;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000001;
				else
					gpio_out = gpio_out & 0xfffffffe;

				gpio_out_en = gpio_out_en | 0x00000001;

				break;

		case 1:
				gpio_in_en  = gpio_in_en & 0xfffffffd;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000002;
				else
					gpio_out = gpio_out & 0xfffffffd;

				gpio_out_en = gpio_out_en | 0x00000002;

				break;

		case 2:
				gpio_in_en  = gpio_in_en & 0xfffffffb;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000004;
				else
					gpio_out = gpio_out & 0xfffffffb;

				gpio_out_en = gpio_out_en | 0x00000004;

				break;

		case 3:
				gpio_in_en  = gpio_in_en & 0xfffffff7;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000008;
				else
					gpio_out = gpio_out & 0xfffffff7;

				gpio_out_en = gpio_out_en | 0x00000008;

				break;

		case 4:
				gpio_in_en  = gpio_in_en & 0xffffffef;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000010;
				else
					gpio_out = gpio_out & 0xffffffef;

				gpio_out_en = gpio_out_en | 0x00000010;

				break;

		case 5:
				gpio_in_en  = gpio_in_en & 0xffffffdf;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000020;
				else
					gpio_out = gpio_out & 0xffffffdf;

				gpio_out_en = gpio_out_en | 0x00000020;

				break;

		case 6:
				gpio_in_en  = gpio_in_en & 0xffffffbf;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000040;
				else
					gpio_out = gpio_out & 0xffffffbf;

				gpio_out_en = gpio_out_en | 0x00000040;

				break;

		case 7:
				gpio_in_en  = gpio_in_en & 0xffffff7f;

				if(wr_data == 1)
					gpio_out = gpio_out | 0x00000080;
				else
					gpio_out = gpio_out & 0xffffff7f;

				gpio_out_en = gpio_out_en | 0x00000080;

				break;

	}
}

int gpio_rd(int index)
{
	int temp;

	switch(index)
	{
		case 0:
				gpio_in_en  = gpio_in_en | 0x00000001;
				gpio_out_en = gpio_out_en & 0xfffffffe;
				temp = gpio_in;
				temp = temp & 0x00000001;
				if(temp == 0x00000001)
					return 1;
				else
					return 0;

				break;

		case 1:
				gpio_in_en  = gpio_in_en | 0x00000002;
				gpio_out_en = gpio_out_en & 0xfffffffd;
				temp = gpio_in;
				temp = temp & 0x00000002;
				if(temp == 0x00000002)
					return 1;
				else
					return 0;

				break;

		case 2:
				gpio_in_en  = gpio_in_en | 0x00000004;
				gpio_out_en = gpio_out_en & 0xfffffffb;
				temp = gpio_in;
				temp = temp & 0x00000004;
				if(temp == 0x00000004)
					return 1;
				else
					return 0;

				break;

		case 3:
				gpio_in_en  = gpio_in_en | 0x00000008;
				gpio_out_en = gpio_out_en & 0xfffffff7;
				temp = gpio_in;
				temp = temp & 0x00000008;
				if(temp == 0x00000008)
					return 1;
				else
					return 0;

				break;

		case 4:
				gpio_in_en  = gpio_in_en | 0x00000010;
				gpio_out_en = gpio_out_en & 0xffffffef;
				temp = gpio_in;
				temp = temp & 0x00000010;
				if(temp == 0x00000010)
					return 1;
				else
					return 0;

				break;

		case 5:
				gpio_in_en  = gpio_in_en | 0x00000020;
				gpio_out_en = gpio_out_en & 0xffffffdf;
				temp = gpio_in;
				temp = temp & 0x00000020;
				if(temp == 0x00000020)
					return 1;
				else
					return 0;

				break;

		case 6:
				gpio_in_en  = gpio_in_en | 0x00000040;
				gpio_out_en = gpio_out_en & 0xffffffbf;
				temp = gpio_in;
				temp = temp & 0x00000040;
				if(temp == 0x00000040)
					return 1;
				else
					return 0;

				break;

		case 7:
				gpio_in_en  = gpio_in_en | 0x00000080;
				gpio_out_en = gpio_out_en & 0xffffff7f;
				temp = gpio_in;
				temp = temp & 0x00000080;
				if(temp == 0x00000080)
					return 1;
				else
					return 0;

				break;
	}

	return 0;
}
