#include "nuclei_sdk_hal.h"
#include "nuclei_uart.h"
#include "nuclei_gpio.h"

#define LEDn 3
static uint32_t LED_CLORK[] = {SOC_LED_RED_GPIO_MASK, SOC_LED_GREEN_GPIO_MASK,SOC_LED_BLUE_GPIO_MASK};



/*!
    \brief      configure led GPIO
    \param[in]  lednum: specify the led to be configured
      \arg        LED1
      \arg        LED2
      \arg        LED3
      \arg        LED4
    \param[out] none
    \retval     none
*/
void gd_eval_led_init(led_typedef_enum lednum)
{

    // gpio_iof_config(GPIO,LED_CLORK[i],IOF_SEL_DEF);
    gpio_enable_output(GPIO,LED_CLORK[lednum]);
    gpio_write(GPIO,LED_CLORK[lednum],1);
}

/*!
    \brief      turn on selected led
    \param[in]  lednum: specify the led to be turned on
      \arg        LED1
      \arg        LED2
      \arg        LED3
      \arg        LED4
    \param[out] none
    \retval     none
*/
void gd_eval_led_on(led_typedef_enum lednum)
{
    gpio_write(GPIO,LED_CLORK[lednum],1);
}

/*!
    \brief      turn off selected led
    \param[in]  lednum: specify the led to be turned off
      \arg        LED1
      \arg        LED2
      \arg        LED3
      \arg        LED4
    \param[out] none
    \retval     none
*/
void gd_eval_led_off(led_typedef_enum lednum)
{
     gpio_write(GPIO,LED_CLORK[lednum],0);
}

/*!
    \brief      toggle selected led
    \param[in]  lednum: specify the led to be toggled
      \arg        LED1
      \arg        LED2
      \arg        LED3
      \arg        LED4
    \param[out] none
    \retval     none
*/
void gd_eval_led_toggle(led_typedef_enum lednum)
{
    gpio_toggle(GPIO,LED_CLORK[lednum]);
}


