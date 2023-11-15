// See LICENSE for license details.
#ifndef _BOARD_SF1_EVAL_H_
#define _BOARD_SF1_EVAL_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include "nuclei_sdk_soc.h"



/* exported types */
typedef enum 
{
    LED1 = 0,
    LED2 = 1,
    LED3 = 2,
} led_typedef_enum;

typedef enum 
{
    KEY_A = 0,
    KEY_B = 1,
    KEY_C = 2,
    KEY_D = 3,
    KEY_CET = 4
} key_typedef_enum;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} keymode_typedef_enum;


// GPIO Bit Offset
#define SOC_LED_RED_GPIO_OFS        0
#define SOC_LED_GREEN_GPIO_OFS      1
#define SOC_LED_BLUE_GPIO_OFS       2
#define SOC_BUTTON_1_GPIO_OFS       3
#define SOC_BUTTON_2_GPIO_OFS       4

// GPIO Bit Mask
#define SOC_LED_RED_GPIO_MASK       (1<<SOC_LED_RED_GPIO_OFS)
#define SOC_LED_GREEN_GPIO_MASK     (1<<SOC_LED_GREEN_GPIO_OFS)
#define SOC_LED_BLUE_GPIO_MASK      (1<<SOC_LED_BLUE_GPIO_OFS)
#define SOC_BUTTON_1_GPIO_MASK      (1<<SOC_BUTTON_1_GPIO_OFS)
#define SOC_BUTTON_2_GPIO_MASK      (1<<SOC_BUTTON_2_GPIO_OFS)
#define SOC_BUTTON_GPIO_MASK        (SOC_BUTTON_1_GPIO_MASK | SOC_BUTTON_2_GPIO_MASK)
#define SOC_LED_GPIO_MASK           (SOC_LED_RED_GPIO_MASK | SOC_LED_GREEN_GPIO_MASK | SOC_LED_BLUE_GPIO_MASK)



void gd_eval_led_init(led_typedef_enum lednum);
void gd_eval_led_on(led_typedef_enum lednum);
void gd_eval_led_off(led_typedef_enum lednum);

void gd_eval_led_toggle(led_typedef_enum lednum);
#ifdef __cplusplus
}
#endif
#endif
