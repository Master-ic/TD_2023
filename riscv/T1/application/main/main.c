#include <stdio.h>

#include "../../../../SoC/anlogic/Board/sf1_eval/Include/nuclei_sdk_hal.h"

//#define LEDn  3
//static uint16_t32_t LED_CLORK[] = {SOC_LED_RED_GPIO_MASK, SOC_LED_GREEN_GPIO_MASK,SOC_LED_BLUE_GPIO_MASK};

#define LEDn  3




//这里遇到了一个小bug，不知道数组合起来为什么不能初始化
int16_t img_array_1[14][28] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 132, 255, 225, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 128, 246, 183, 128, 46, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 91, 254, 134, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54, 235, 204, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 158, 252, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 63, 251, 165, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 107, 254, 138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 182, 229, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 17, 232, 133, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 133, 254, 105, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 254, 27, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 18, 227, 194, 3, 0, 0, 0, 0, 0, 0, 30, 0, 0, 0, 0, 0, 0, 0, 0,
};

  int16_t img_array_2[14][28] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 58, 254, 115, 0, 0, 0, 0, 25, 139, 155, 242, 235, 128, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 58, 254, 75, 0, 0, 0, 83, 224, 251, 155, 152, 254, 211, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 58, 254, 104, 0, 0, 82, 249, 217, 60, 0, 37, 254, 120, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 58, 254, 72, 0, 18, 247, 159, 14, 0, 7, 201, 254, 69, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 35, 239, 147, 1, 5, 155, 72, 0, 4, 193, 253, 122, 6, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 216, 254, 97, 0, 0, 13, 73, 225, 254, 121, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 79, 244, 248, 226, 226, 231, 254, 243, 115, 6, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 114, 177, 254, 254, 235, 152, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};



int16_t  weight_1_1[5 ][5 ] = {
  6, 0, 27, 41, 53,
  -25, 19, -3, 11, 62,
  -15, -13, 14, -11, -10,
  -46, -40, -37, -42, -39,
  -25, -29, -42, -30, -36,
};

int16_t weight_1_2[ 5][ 5] = {
  8, 0, 6, -11, -3,
  26, -16, 25, 10, 36,
  15, 18, 33, 70, 65,
  13, 58, 108, 118, 46,
  49, 29, 88, 53, 78,
};


int16_t weight_1_3[ 5][ 5] = {
  33, 26, 51, 41, 71,
  27, 27, 32, 12, -8,
  -40, 2, -32, -35, -43,
  -36, -61, -50, -68, -27,
  -43, -39, -38, 3, -7,
};



int16_t weight_2_11[ 5][ 5] = {
  1, 3, 1, 12, -3,
  -7, -7, 10, -14, -21,
  -22, -23, -18, -31, -8,
  -25, -42, -41, -6, -8,
  -30, -40, -28, -3, 24,
};


int16_t weight_2_12[ 5][ 5] = {
  -2, -22, 5, -6, -28,
  0, -19, 31, 71, 12,
  -56, 30, 74, 33, -42,
  15, 50, 17, -42, -11,
  42, 22, -26, -8, -12,
};


int16_t weight_2_13[ 5][ 5] = {
  -16, -21, 12, -21, -14,
  -4, 8, 20, -23, -11,
  16, 6, -36, -29, -27,
  3, -29, -13, -6, -13,
  -25, -17, -10, 5, -11,
};

int16_t weight_2_21[ 5][ 5] = {
  0, 13, 6, 17, -4,
  9, -12, 14, 11, -4,
  7, 24, 26, 10, -6,
  11, 42, 28, 4, -22,
  18, 22, -13, -16, -10,
};


int16_t weight_2_22[ 5][ 5] = {
  0, -65, -82, -47, -5,
  21, 30, 15, 32, -13,
  42, 67, 72, 48, -9,
  -5, -17, -14, 2, 0,
  -35, -26, -25, -6, -30,
};


int16_t weight_2_23[ 5][ 5] = {
  -27, 13, 16, -17, -6,
  -20, -19, -16, -9, 0,
  5, -2, 5, 22, 1,
  12, 41, 60, 16, -6,
  21, 29, 11, -16, -16,
};

int16_t weight_2_31[ 5][ 5] = {
  4, -23, -16, -7, -2,
  11, 22, 8, -21, -7,
  21, 26, 0, 5, 0,
  46, 25, 16, 18, -1,
  22, 4, -3, -8, 7,
};


int16_t weight_2_32[ 5][ 5] = {
  2, 13, 30, 46, -29,
  21, 24, 29, 66, -22,
  -26, -52, -9, 46, 19,
  -28, -31, -22, 4, 20,
  21, 2, -9, 5, -33,
};


int16_t weight_2_33[ 5][ 5] = {
  -22, -27, -24, -46, -34,
  -4, 21, -8, -38, -42,
  0, -2, 16, -44, -56,
  28, 22, 31, -8, -33,
  40, 25, 10, -8, -8,
};


int16_t bias[3] = {
  7,
  15,
  47,
};

int16_t bias_2[3] = {
  15,
 -43,
 19,
};


int16_t test_case[24][24] = {
  7, 7, 7, 7, 7, 7, 7, 7, 7, -7, -60, -121, -164, -171, -152, -114, -79, -37, -2, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 7, -1, -47, -117, -121, -76, -58, -79, -33, -17, -24, 3, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 7, -24, -95, -126, -63, -3, 29, 21, 16, 5, 3, 2, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, -2, -62, -110, -66, -21, -26, -7, 10, 20, 16, 10, 8, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, -18, -83, -74, -17, -39, -62, -49, -14, 9, 7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, -38, -66, -23, -5, -57, -85, -41, 0, 7, 7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 4, -45, -25, -2, -18, -61, -72, -19, 9, 7, 7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, -15, -51, -9, 2, -46, -87, -52, -5, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, -45, -59, -21, -33, -71, -88, -36, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 4, -62, -46, -22, -57, -91, -87, -12, 7, 7, 2, 3, 2, 3, 4, 7, 7, 7, 7,
  7, 7, 7, 7, 7, -4, -46, -20, -22, -55, -108, -68, -6, -16, -36, -76, -103, -114, -94, -70, -31, -6, 7, 7,
  7, 7, 7, 7, 7, -11, -14, 17, -21, -51, -102, -62, -39, -94, -141, -195, -248, -261, -214, -172, -104, -37, 7, 7,
  7, 7, 7, 7, 7, -8, 4, 23, -29, -72, -120, -94, -115, -171, -193, -195, -245, -235, -188, -165, -131, -51, 7, 7,
  7, 7, 7, 7, 7, 5, 17, -3, -43, -86, -167, -139, -149, -125, -99, -76, -104, -137, -135, -134, -130, -47, 7, 7,
  7, 7, 7, 7, 7, 17, 34, -22, -55, -97, -190, -121, -46, 9, -16, -7, -8, -32, -84, -107, -87, -31, 7, 7,
  7, 7, 7, 7, 7, 25, 47, -34, -84, -129, -170, -42, 77, 46, -54, -104, -45, -15, -55, -52, -45, -5, 7, 7,
  7, 7, 7, 7, 7, 31, 78, -29, -105, -167, -184, -113, -67, -107, -213, -173, -43, -34, -27, -25, -15, 2, 7, 7,
  7, 7, 7, 7, 7, 27, 107, 28, -79, -166, -196, -251, -272, -278, -216, -76, 3, 14, 1, -5, 1, 8, 7, 7,
  7, 7, 7, 7, 7, 14, 111, 119, 26, -53, -104, -160, -160, -111, -15, 43, 49, 22, 2, 1, 9, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 70, 152, 148, 106, 77, 51, 62, 105, 113, 77, 35, 7, 2, 9, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 23, 97, 153, 187, 196, 187, 171, 135, 94, 45, 14, 9, 9, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 30, 61, 99, 118, 125, 107, 70, 35, 17, 10, 8, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
  7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
};
int16_t fc_weight[10][48] = {
  -2, 24, -2, -8, 19, 19, -4, 20, 17, -5, -8, 34, -3, -18, 0, 1, -3, 2, 15, 6, -14, -11, -25, -3, -33, -29, -14, 4, -15, 18, 26, -6, -11, 9, 3, 2, -3, -6, 13, 35, 20, -17, -32, -4, 39, -21, -52, 10,
  -2, -17, 48, 13, 9, 9, 10, -13, 24, 15, -17, -20, 20, 40, -32, -7, 1, 23, -35, -15, 11, -12, -19, -24, 2, -12, -17, -14, 17, -12, -9, 32, -39, 49, -44, -42, -35, 64, -2, -2, -19, 16, -11, 5, -59, 33, 3, -6,
  -29, -11, -19, -28, 15, 17, 22, 27, 56, 41, 9, 0, -3, -19, -34, -29, 30, 6, 14, -15, 58, 20, -3, -15, 18, -6, 2, 20, -25, -6, 4, 42, 28, 40, 61, 6, -2, -18, -10, -12, -48, -15, -35,
2, 0, -6, 12, 16,
  -52, -7, 15, 30, -14, 17, 1, 18, -31, -37, -48, 3, 1, 28, 24, 23, 30, 20, 8, 4, 23, 3, 11, 11, 0, 1, 17, -4, 37, -6, 20, -16, -6, 38, 23, -2, -24, 0, -5, -9, -26, 19, 18, -4, -19, -8, 0, 8,
  20, 32, 32, 44, 39, -23, -13, 26, -17, -37, 6, -20, 27, 22, -11, -11, -7, -48, -52, -41, -5, 23, 0, -17, 25, 24, 30, 28, -8, -10, -26, -9, 53, -18, -16, -9, 8, -17, 44, -17, 18, 15,
-14, -6, -16, 1, 8, -15,
  1, 18, -22, -25, -26, -13, -32, -77, 0, 1, 18, -23, -19, 18, 31, 41, -16, 2, 8, 57, -4, 8, 14, 37, 24, 5, -2, 0, 44, 4, 12, -18, 13, -29, -37, 33, 27, -15, -5, 3, 21, 12, 35, -8, 0,
-5, 11, 5,
  24, 44, 24, -25, 6, -1, 11, -36, -10, 23, 41, 42, -19, -26, -10, -7, -15, -30, -13, -1, -28, -30, 15, 35, -31, -22, 8, 9, -27, 5, 14, 13, -12, -47, -68, 26, -12, -63, -59, 9, 13, -17, 9, 17, 28, 16, 11, 13,
  -16, -45, -31, 24, 23, 35, 11, 13, 15, -15, 15, 12, 19, 11, 0, -5, 21, 28, 43, 5, 30, 23, 2, 0, 19, -23, -13, 41, -3, -30, -34, -24, 17, -2, 9, -34, -4, 12, 57, 4, 14, -10, -41, -22, -57, 1, 0, 0,
  14, -1, -6, 7, -10, -18, 13, 23, 40, 42, -10, -29, -6, -48, 11, 16, -29, 15, -1, 20, -7, 12, 3, 21, -17, -8, -12, 18, -44, -1, 7, 5, -9, 20, 23, 25, 50, 18, -23, 4, 0, 25, -17, 4, 11, -19, 0, -20,
  22, 40, 14, -5, -12, -23, 14, 13, -47, -55, -8, 6, 21, 36, -19, 2, -13, 10, 28, 8, -50, 10, 7, 13, 0, 31, -3, -54, -14, 19, -29, -66, -60, -32, 9, 1, 1, 22, 30, -6, 10, 15, 55, -4, 3, 0, -15, 9,
};


void convolution_real(
  int16_t img_h, int16_t img_w,
  int16_t image_array[img_h][img_w],

  int16_t kern_h, int16_t kern_w,
  int16_t weights[kern_h][kern_w],

  int16_t bias,

  int16_t out_h, int16_t out_w,
  int output[out_h][out_w]
) {

  int16_t i, j, m, n;
  int value;

  for(i=0; i<out_h; i++) {
    for(j=0; j<out_w; j++) {

      value = 0;
      for(m=0; m<kern_h; m++) {
        for(n=0; n<kern_w; n++) {
          value += (int16_t)image_array[i+m][j+n] * weights[m][n];
        }
      }

      value += bias;

      output[i][j] = value;

    }
  }

}


//打印观测函数
void print16_t_array(int16_t W, int16_t H, int16_t arr[W][H]) {

  int16_t i, j;

  anl_printf("array[%d][%d] = {\n", W, H);

  for(i=0; i<W; i++) {
	  anl_printf("  ");
    for(j=0; j<H; j++) {
    	anl_printf("%d, ", arr[i][j]);
    }
    anl_printf("\n");
  }

  anl_printf("};\n");
}



void print_int_array(int16_t W, int16_t H, int arr[W][H]) {

  int16_t i, j;

  anl_printf("array[%d][%d] = {\n", W, H);

  for(i=0; i<W; i++) {
	  anl_printf("  ");
    for(j=0; j<H; j++) {
    	anl_printf("%d, ", arr[i][j]);
    }
    anl_printf("\n");
  }

  anl_printf("};\n");
}



void convolution(int16_t img_h, int16_t img_w,
		int16_t img_array_1[14][28],
		int16_t img_array_2[14][28],




                 int16_t kern_h, int16_t kern_w,
                 int16_t weights[kern_h][kern_w],
                 int16_t bias,
                 int16_t out_h, int16_t out_w,
                 int16_t output[out_h][out_w]) {

  int16_t i, j, m, n;
  int value;

  for(i=0; i<img_h-kern_h+1; i++) {
    for(j=0; j<img_w-kern_w+1; j++) {

      value = 0;
      for(m=0; m<kern_h; m++) {
        for(n=0; n<kern_w; n++) {
          if(i+m<=14){
          value += (int16_t)img_array_1[i+m][j+n] * weights[m][n];}
          else
          value += (int16_t)img_array_2[i+m-14][j+n] * weights[m][n];

        }
      }

      value = value >> 8;
      value += bias;

      if(value > 2047) value = 2047;
      else if(value < -2048) value = -2048;


      output[i][j] = value;
//      if(  output[i][j]!=test_case[i][j])
//    	  printf("error\n");
    }
  }

}


void max_pool_relu(int16_t IMAGE_H,int16_t IMAGE_W,int16_t POOL_H,int16_t POOL_W, int16_t image[IMAGE_H][IMAGE_W],
                   int16_t pooled_image[IMAGE_H/POOL_H][IMAGE_W/POOL_W]) {

  int16_t i, j, m, n, max;

  for(i=0; i<IMAGE_H/POOL_H; i++) {
    for(j=0; j<IMAGE_W/POOL_W; j++) {

      max = image[i*POOL_H][j*POOL_W];

      for(m=0; m<POOL_H; m++) {
        for(n=0; n<POOL_W; n++) {
          if(image[i*POOL_H+m][j*POOL_W+n] > max) {
            max = image[i*POOL_H+m][j*POOL_W+n];
          }
        }
      }

      pooled_image[i][j] = max > 0 ? max : 0;

    }
  }

}


void max_pool_relu_int(int16_t IMAGE_H,int16_t IMAGE_W,int16_t POOL_H,int16_t POOL_W, int image[IMAGE_H][IMAGE_W],
                   int pooled_image[IMAGE_H/POOL_H][IMAGE_W/POOL_W]) {

  int i, j, m, n, max;

  for(i=0; i<IMAGE_H/POOL_H; i++) {
    for(j=0; j<IMAGE_W/POOL_W; j++) {

      max = image[i*POOL_H][j*POOL_W];

      for(m=0; m<POOL_H; m++) {
        for(n=0; n<POOL_W; n++) {
          if(image[i*POOL_H+m][j*POOL_W+n] > max) {
            max = image[i*POOL_H+m][j*POOL_W+n];
          }
        }
      }

      pooled_image[i][j] = max > 0 ? max : 0;

    }
  }

}


void convolution_2(
  int16_t img_h, int16_t img_w,
  int16_t image_array[img_h][img_w],

  int16_t kern_h, int16_t kern_w,
  int16_t weights[kern_h][kern_w],

  int16_t bias,

  int16_t out_h, int16_t out_w,
  int16_t output[out_h][out_w]
) {

  int16_t i, j, m, n;
  int16_t value;

  for(i=0; i<out_h; i++) {
    for(j=0; j<out_w; j++) {

      value = 0;
      for(m=0; m<kern_h; m++) {
        for(n=0; n<kern_w; n++) {
          value += (int16_t)image_array[i+m][j+n] * weights[m][n];
        }
      }

      value += bias;

      output[i][j] = value;

    }
  }

}




void add_bias(
		int16_t W, int H,
		int input1[W][H],
		int input2[W][H],

		int16_t bias,
  int output[W][H],
  int16_t zero
) {

//print_array(8,8,input1);
  int i, j;
int sum;

  for(i=0; i<W; i++) {
    for(j=0; j<H; j++) {

{if(zero==1)
       sum=input1[i][j] ;
  else
     sum=input1[i][j] + input2[i][j];}

      //sum=sum>>7;
        sum += bias;
      output[i][j] = sum;

    }
  }

}

void add_bias_real(
		int16_t W, int H,
		int input1[W][H],
		int input2[W][H],

		int16_t bias,
		int16_t output[W][H],
  int16_t zero
) {

//print_array(8,8,input1);
  int i, j;
int sum;

  for(i=0; i<W; i++) {
    for(j=0; j<H; j++) {

{if(zero==1)
       sum=input1[i][j] ;
  else
     sum=input1[i][j] + input2[i][j];}

      //sum=sum>>7;
        sum += bias;
      output[i][j] = sum;

    }
  }

}




void flattenAndMerge(int matrix1[4][4], int matrix2[4][4], int matrix3[4][4], int result[48]) {
    int16_t index = 0;

    // 将矩阵1展平并合并到结果矩阵
    for (int16_t i = 0; i < 4; i++) {
        for (int16_t j = 0; j < 4; j++) {
            result[index] = matrix1[i][j];
            index++;
        }
    }

    // 将矩阵2展平并合并到结果矩阵
    for (int16_t i = 0; i < 4; i++) {
        for (int16_t j = 0; j < 4; j++) {
            result[index] = matrix2[i][j];
            index++;
        }
    }

    // 将矩阵3展平并合并到结果矩阵
    for (int16_t i = 0; i < 4; i++) {
        for (int16_t j = 0; j < 4; j++) {
            result[index] = matrix3[i][j];
            index++;
        }
    }
}


void fc_opt(int flattened_data[48], int16_t fc_weight[10][48], int result[10]) {
    for (int16_t i = 0; i < 10; i++) {
        int sum = 0;
        for (int16_t j = 0; j < 48; j++) {
            sum += flattened_data[j] * fc_weight[i][j];
        }
        result[i] = sum>>7 ;
    }
}

int16_t findMaxIndex(int result[10]) {
    int16_t maxIndex = 0;
    int maxValue = result[0];

    for (int16_t i = 1; i < 10; i++) {
        if (result[i] > maxValue) {
            maxValue = result[i];
            maxIndex = i;
        }
    }

    for(int16_t i = 0; i < 5; i++){
    printf("\nThe numbers for image recognition are:%d",maxIndex);}
    return maxIndex;
}


int main(){

int16_t fc_weight[10][48]= {
	  -2, 24, -2, -8, 19, 19, -4, 20, 17, -5, -8, 34, -3, -18, 0, 1, -3, 2, 15, 6, -14, -11, -25, -3, -33, -29, -14, 4, -15, 18, 26, -6, -11, 9, 3, 2, -3, -6, 13, 35, 20, -17, -32, -4, 39, -21, -52, 10,
	  -2, -17, 48, 13, 9, 9, 10, -13, 24, 15, -17, -20, 20, 40, -32, -7, 1, 23, -35, -15, 11, -12, -19, -24, 2, -12, -17, -14, 17, -12, -9, 32, -39, 49, -44, -42, -35, 64, -2, -2, -19, 16, -11, 5, -59, 33, 3, -6,
	  -29, -11, -19, -28, 15, 17, 22, 27, 56, 41, 9, 0, -3, -19, -34, -29, 30, 6, 14, -15, 58, 20, -3, -15, 18, -6, 2, 20, -25, -6, 4, 42, 28, 40, 61, 6, -2, -18, -10, -12, -48, -15, -35,
	2, 0, -6, 12, 16,
	  -52, -7, 15, 30, -14, 17, 1, 18, -31, -37, -48, 3, 1, 28, 24, 23, 30, 20, 8, 4, 23, 3, 11, 11, 0, 1, 17, -4, 37, -6, 20, -16, -6, 38, 23, -2, -24, 0, -5, -9, -26, 19, 18, -4, -19, -8, 0, 8,
	  20, 32, 32, 44, 39, -23, -13, 26, -17, -37, 6, -20, 27, 22, -11, -11, -7, -48, -52, -41, -5, 23, 0, -17, 25, 24, 30, 28, -8, -10, -26, -9, 53, -18, -16, -9, 8, -17, 44, -17, 18, 15,
	-14, -6, -16, 1, 8, -15,
	  1, 18, -22, -25, -26, -13, -32, -77, 0, 1, 18, -23, -19, 18, 31, 41, -16, 2, 8, 57, -4, 8, 14, 37, 24, 5, -2, 0, 44, 4, 12, -18, 13, -29, -37, 33, 27, -15, -5, 3, 21, 12, 35, -8, 0,
	-5, 11, 5,
	  24, 44, 24, -25, 6, -1, 11, -36, -10, 23, 41, 42, -19, -26, -10, -7, -15, -30, -13, -1, -28, -30, 15, 35, -31, -22, 8, 9, -27, 5, 14, 13, -12, -47, -68, 26, -12, -63, -59, 9, 13, -17, 9, 17, 28, 16, 11, 13,
	  -16, -45, -31, 24, 23, 35, 11, 13, 15, -15, 15, 12, 19, 11, 0, -5, 21, 28, 43, 5, 30, 23, 2, 0, 19, -23, -13, 41, -3, -30, -34, -24, 17, -2, 9, -34, -4, 12, 57, 4, 14, -10, -41, -22, -57, 1, 0, 0,
	  14, -1, -6, 7, -10, -18, 13, 23, 40, 42, -10, -29, -6, -48, 11, 16, -29, 15, -1, 20, -7, 12, 3, 21, -17, -8, -12, 18, -44, -1, 7, 5, -9, 20, 23, 25, 50, 18, -23, 4, 0, 25, -17, 4, 11, -19, 0, -20,
	  22, 40, 14, -5, -12, -23, 14, 13, -47, -55, -8, 6, 21, 36, -19, 2, -13, 10, 28, 8, -50, 10, 7, 13, 0, 31, -3, -54, -14, 19, -29, -66, -60, -32, 9, 1, 1, 22, 30, -6, 10, 15, 55, -4, 3, 0, -15, 9,
	};


int16_t con_out_1[24][24];
int16_t max_out_1[12][12];
int con_out_2_11[8][8];
int con_out_2_21[8][8];
int con_out_2_31[8][8];
int con_out_2_1[8][8];
int con_out_2_2[8][8];
int con_out_2_3[8][8];
//第二次池化
int max_out_2_1[4][4];
int max_out_2_2[4][4];
int max_out_2_3[4][4];
////全连接
int fc_pixel[48];
int fc_outdata[10];


//组1
printf("Layer 1 channel 1 convolution results:\n");
convolution(28,28,img_array_1,img_array_2,5,5,weight_1_1,bias[0],24,24,con_out_1);
print16_t_array(24,24,con_out_1);

printf("Layer 1 channel 1 pooling results:\n");
max_pool_relu(24,24,2,2,con_out_1,max_out_1);
print16_t_array(12,12,max_out_1);

printf("Layer 2 channel 1_1 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_11,0,8,8,con_out_2_11);
print_int_array(8,8,con_out_2_11);
printf("Layer 2 channel 1_2 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_21,0,8,8,con_out_2_21);
print_int_array(8,8,con_out_2_21);
printf("Layer 2 channel 1_3 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_31,0,8,8,con_out_2_31);
print_int_array(8,8,con_out_2_31);


//节省资源，累加运算
add_bias(8,8,con_out_2_11,con_out_2_1,0,con_out_2_1,1);
add_bias(8,8,con_out_2_21,con_out_2_1,0,con_out_2_2,1);
add_bias(8,8,con_out_2_31,con_out_2_1,0,con_out_2_3,1);



//组2
printf("Layer 1 channel 2 convolution results:\n");
convolution(28,28,img_array_1,img_array_2,5,5,weight_1_2,bias[1],24,24,con_out_1);
print16_t_array(24,24,con_out_1);

printf("Layer 1 channel 2 pooling results:\n");
max_pool_relu(24,24,2,2,con_out_1,max_out_1);
print16_t_array(12,12,max_out_1);

printf("Layer 2 channel 2_1 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_12,0,8,8,con_out_2_11);
print_int_array(8,8,con_out_2_11);
printf("Layer 2 channel 2_2 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_22,0,8,8,con_out_2_21);
print_int_array(8,8,con_out_2_21);
printf("Layer 2 channel 2_3 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_32,0,8,8,con_out_2_31);
print_int_array(8,8,con_out_2_31);




add_bias(8,8,con_out_2_1,con_out_2_11,0,con_out_2_1,0);
add_bias(8,8,con_out_2_2,con_out_2_21,0,con_out_2_2,0);
add_bias(8,8,con_out_2_3,con_out_2_31,0,con_out_2_3,0);

printf("Layer 1 channel 3 convolution results:\n");
convolution(28,28,img_array_1,img_array_2,5,5,weight_1_3,bias[2],24,24,con_out_1);
print16_t_array(24,24,con_out_1);

printf("Layer 1 channel 3 pooling results:\n");
max_pool_relu(24,24,2,2,con_out_1,max_out_1);
print16_t_array(12,12,max_out_1);



printf("Layer 2 channel 3_1 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_13,0,8,8,con_out_2_11);
print_int_array(8,8,con_out_2_11);
printf("Layer 2 channel 3_2 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_23,0,8,8,con_out_2_21);
print_int_array(8,8,con_out_2_21);
printf("Layer 2 channel 3_3 convolution results:\n");
convolution_real(12,12,max_out_1,5,5,weight_2_33,0,8,8,con_out_2_31);
print_int_array(8,8,con_out_2_31);




add_bias(8,8,con_out_2_1,con_out_2_11,bias_2[0],con_out_2_1,0);
add_bias(8,8,con_out_2_2,con_out_2_21,bias_2[1],con_out_2_2,0);
add_bias(8,8,con_out_2_3,con_out_2_31,bias_2[2],con_out_2_3,0);



printf("Layer 2 channel 1 final convolution results:\n");
print_int_array(8,8,con_out_2_1);

printf("Layer 2 channel 2 final convolution results:\n");
print_int_array(8,8,con_out_2_2);

printf("Layer 2 channel 3 final convolution results:\n");
print_int_array(8,8,con_out_2_3);






max_pool_relu_int(8,8,2,2,con_out_2_1,max_out_2_1);
max_pool_relu_int(8,8,2,2,con_out_2_2,max_out_2_2);
max_pool_relu_int(8,8,2,2,con_out_2_3,max_out_2_3);

printf("Layer 2 channel 1 final pooling results:\n");
print_int_array(4,4,max_out_2_1);

printf("Layer 2 channel 2 final pooling results:\n");
print_int_array(4,4,max_out_2_2);

printf("Layer 2 channel 3 final pooling results:\n");
print_int_array(4,4,max_out_2_3);


flattenAndMerge(max_out_2_1,max_out_2_2,max_out_2_3,fc_pixel);





fc_opt(fc_pixel,fc_weight,fc_outdata);


printf("The result of the full connection is:\n");
for(int i=0;i<=9;i++)
printf("%d\t", fc_outdata[i]);

int detect_number;
detect_number=findMaxIndex(fc_outdata);

 return 0;
}
