// See LICENSE for license details.
#ifndef _NUCLEI_GPIO_H
#define _NUCLEI_GPIO_H

#ifdef __cplusplus
 extern "C" {
#endif

#define GPIO_INPUT_VAL      (0x00)
#define GPIO_INPUT_EN       (0x04)
#define GPIO_OUTPUT_EN      (0x08)
#define GPIO_OUTPUT_VAL     (0x0C)
#define GPIO_PUE            (0x10)
#define GPIO_DS             (0x14)
#define GPIO_OD             (0x18)
#define GPIO_PUP            (0x1C)
#define GPIO_RISE_IE        (0x20)
#define GPIO_RISE_IP        (0x24)
#define GPIO_FALL_IE        (0x28)
#define GPIO_FALL_IP        (0x2C)
#define GPIO_HIGH_IE        (0x30)
#define GPIO_HIGH_IP        (0x34)
#define GPIO_LOW_IE         (0x38)
#define GPIO_LOW_IP         (0x3C)
#define GPIO_IOF_EN         (0x40)
#define GPIO_IOF_SEL0       (0x44)
#define GPIO_IOF_SEL1       (0x48)
#define GPIO_IRQ_MASK       (0x4c)
#define GPIO_EVENT_RISE_EN  (0x50)
#define GPIO_EVENT_FALL_EN  (0x54)
#define GPIO_OUTPUT_XOR     (0x58)


typedef enum iof_func {
    IOF_SEL_DEF =0,
    IOF_SEL_0 = 1,
    IOF_SEL_1 = 2,
    IOF_SEL_2 = 3,
    IOF_SEL_3 = 4,
} IOF_FUNC;

typedef enum gpio_int_type {
    GPIO_INT_RISE = 0,
    GPIO_INT_FALL = 1,
    GPIO_INT_HIGH = 2,
    GPIO_INT_LOW = 3
} GPIO_INT_TYPE;

int32_t gpio_iof_config(GPIO_TypeDef *gpio, uint32_t mask, IOF_FUNC func);
int32_t gpio_enable_output(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_enable_input(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_write(GPIO_TypeDef *gpio, uint32_t mask, uint32_t value);
int32_t gpio_toggle(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_read(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_set_pue(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_set_ds(GPIO_TypeDef *gpio, uint32_t mask, uint32_t value);
int32_t gpio_set_outxor(GPIO_TypeDef *gpio, uint32_t mask, uint32_t value);
int32_t gpio_enable_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type);
int32_t gpio_disable_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type);
int32_t gpio_clear_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type);

int32_t gpio_output_pup(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_output_od(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_set_soft_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type);
int32_t gpio_enable_event_rise(GPIO_TypeDef *gpio, uint32_t mask);
int32_t gpio_enable_event_fall(GPIO_TypeDef *gpio, uint32_t mask);

#ifdef __cplusplus
}
#endif
#endif /* _NUCLEI_GPIO_H */
