#include "nuclei.h"
#include "nuclei_gpio.h"

int32_t gpio_iof_config(GPIO_TypeDef *gpio, uint32_t mask, IOF_FUNC func)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    switch (func) {
        case IOF_SEL_DEF:
            gpio->IOF_EN &= ~mask;
            break;
        case IOF_SEL_0:
            gpio->IOF_SEL0 &= ~mask;
            gpio->IOF_SEL1 &= ~mask;
            gpio->IOF_EN |= mask;
            break;
        case IOF_SEL_1:
            gpio->IOF_SEL1 &= ~mask;
            gpio->IOF_SEL0 |= mask;
            gpio->IOF_EN |= mask;
            break;
        case IOF_SEL_2:
            gpio->IOF_SEL1 |= mask;
            gpio->IOF_SEL0 &= ~mask;
            gpio->IOF_EN |= mask;
            break;
        case IOF_SEL_3:
            gpio->IOF_SEL0 |= mask;
            gpio->IOF_SEL1 |= mask;
            gpio->IOF_EN |= mask;
            break;
        default:
            break;
    }
    return 0;
}

int32_t gpio_enable_output(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->OUTPUT_EN |= mask;
    gpio->INPUT_EN &= ~mask;
    return 0;
}

int32_t gpio_enable_input(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->INPUT_EN |= mask;
    gpio->OUTPUT_EN &= ~mask;
    return 0;
}

int32_t gpio_output_od(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->OUTPUT_EN |= mask;
    gpio->INPUT_EN  &= ~mask;
    gpio->OD |= mask;
    return 0;
}

int32_t gpio_output_pup(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->INPUT_EN |= mask;
    gpio->OUTPUT_EN &= ~mask;
    gpio->PUP |= mask;
    return 0;
}

int32_t gpio_input_pue(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->OUTPUT_EN |= mask;
    gpio->INPUT_EN &= ~mask;
    gpio->PDE |= mask;
    return 0;
}

int32_t gpio_input_pde(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->INPUT_EN |= mask;
    gpio->OUTPUT_EN &= ~mask;
    gpio->PDE |=mask;
    return 0;
}


int32_t gpio_enable_event_rise(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->EVENT_RISE_EN |= mask;
    return 0;
}

int32_t gpio_enable_event_fall(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->EVENT_FALL_EN |= mask;
    return 0;
}


int32_t gpio_write(GPIO_TypeDef *gpio, uint32_t mask, uint32_t value)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    // If value != 0, mean set gpio pin high, otherwise set pin low
    if (value) {
        gpio->OUTPUT_VAL |= (mask);
    } else {
        gpio->OUTPUT_VAL &= ~(mask);
    }
    return 0;
}

int32_t gpio_toggle(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->OUTPUT_VAL = (mask ^ gpio->OUTPUT_VAL);
    return 0;
}


int32_t gpio_read(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    return gpio->INPUT_VAL & mask;
}

int32_t gpio_set_pue(GPIO_TypeDef *gpio, uint32_t mask)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->PULLUP_EN |= (mask);
    return 0;
}

int32_t gpio_set_ds(GPIO_TypeDef *gpio, uint32_t mask, uint32_t value)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->DRIVE |= (mask & value);
    return 0;
}

int32_t gpio_set_outxor(GPIO_TypeDef *gpio, uint32_t mask, uint32_t value)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    gpio->OUTPUT_XOR |= (mask & value);
    return 0;
}

int32_t gpio_enable_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    switch (type) {
        case GPIO_INT_RISE:
            gpio->RISE_IE |=mask;
            break;
        case GPIO_INT_FALL:
            gpio->FALL_IE  |=mask;
            break;
        case GPIO_INT_HIGH:
            gpio->HIGH_IE  |=mask;
            break;
        case GPIO_INT_LOW:
            gpio->LOW_IE  |=mask;
            break;
        default:
            break;
    }
    return 0;
}

int32_t gpio_disable_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    switch (type) {
        case GPIO_INT_RISE:
            gpio->RISE_IE &= ~mask;
            break;
        case GPIO_INT_FALL:
            gpio->FALL_IE &= ~mask;
            break;
        case GPIO_INT_HIGH:
            gpio->HIGH_IE &= ~mask;
            break;
        case GPIO_INT_LOW:
            gpio->LOW_IE &= ~mask;
            break;
        default:
            break;
    }
    return 0;
}

int32_t gpio_clear_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    switch (type) {
        case GPIO_INT_RISE:
            gpio->RISE_IP &= ~mask;
            break;
        case GPIO_INT_FALL:
            gpio->FALL_IP &= ~mask;
            break;
        case GPIO_INT_HIGH:
            gpio->HIGH_IP &= ~mask;
            break;
        case GPIO_INT_LOW:
            gpio->LOW_IP &= ~mask;
            break;
        default:
            break;
    }
    return 0;
}


int32_t gpio_set_soft_interrupt(GPIO_TypeDef *gpio, uint32_t mask, GPIO_INT_TYPE type)
{
    if (__RARELY(gpio == NULL)) {
        return -1;
    }
    switch (type) {
        case GPIO_INT_RISE:
            gpio->RISE_IP |= mask;
            break;
        case GPIO_INT_FALL:
            gpio->FALL_IP |= mask;
            break;
        case GPIO_INT_HIGH:
            gpio->HIGH_IP |= mask;
            break;
        case GPIO_INT_LOW:
            gpio->LOW_IP |= mask;
            break;
        default:
            break;
    }
    return 0;
}

