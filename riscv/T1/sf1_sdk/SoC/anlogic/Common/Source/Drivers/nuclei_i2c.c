#include "nuclei_i2c.h"

/**
 * @brief I2C data transmitte.
 * @param i2c: I2C device.
 * @param data: data to be transmitted.
 * @return This function has no return.
 */
void i2c_data_transmit(I2C_TypeDef * i2c,uint8_t data)
{
    i2c->TXR_RXR=data;
    i2c->CR_SR=0x10;
    while(i2c_flag_get(i2c,TIP));
}

/**
 * @brief Write I2C data to TX register.
 * @param i2c: I2C device.
 * @param data: data to be write.
 * @return This function has no return.
 */
void i2c_data_write(I2C_TypeDef * i2c,uint8_t data)
{
    i2c->TXR_RXR=data;
}

/**
 * @brief Read I2C data.
 * @param i2c: I2C device.
 * @return I2C RX data.
 */
uint8_t i2c_data_read(I2C_TypeDef * i2c)
{
     return i2c->TXR_RXR;
}

/**
 * @brief I2C flag check.
 * @param i2c: I2C device.
 * @param flag: I2C state flag.
 * @return I2C state flag.
 */
uint32_t i2c_flag_get(I2C_TypeDef * i2c,I2C_FLAG flag)
{
    return i2c->CR_SR & flag;
}

/**
 * @brief I2C data receive.
 * @param i2c: I2C device.
 * @return RX register value.
 */
uint8_t i2c_data_receive(I2C_TypeDef * i2c)
{
    i2c->CR_SR=0x20;
    while(i2c_flag_get(i2c,TIP));
     return i2c->TXR_RXR;
}

/**
 * @brief I2C initial.
 * @param i2c: I2C device.
 * @param PRER: I2C Prescaler value.
 * @param trise: scl delay register.
 * @param fltr: filter register.
 * @return This function has no return.
 */
void i2c_init(I2C_TypeDef * i2c,uint16_t PRER,uint8_t trise,uint8_t fltr)
{
    i2c->PRERhi=(uint8_t)(PRER>>8);
    i2c->PRERlo=(uint8_t)(PRER&0xFF);
    i2c->trise = trise;
    i2c->fltr = fltr;
}
/**
 * @brief I2C slave device address and R/W mode config.
 * @param i2c: I2C device.
 * @param address: slave device address.
 * @param mode: R/W mode.
 * @return This function has no return.
 */
void i2c_mode_addr_config(I2C_TypeDef * i2c,uint8_t address,I2C_WR_MODE mode)
{
    if (__RARELY(i2c == NULL)) 
    {
        return ;
    }
    i2c->TXR_RXR =(uint8_t)((address<<I2C_ADDRESS_OFS) | (mode & I2C_WR_MODE_MASK) );   //slave address
}

/**
 * @brief Stop I2C data transmitting.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_close_transmit(I2C_TypeDef * i2c)
{
    i2c->CR_SR=0x50;              //close 
}

/**
 * @brief Stop I2C data receiving.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_close_receive(I2C_TypeDef * i2c)
{
    i2c->CR_SR=0x68;              //close 
}

/**
 * @brief I2C enable.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_enable(I2C_TypeDef * i2c)
{
    i2c->CTR=(uint8_t)0x1<<7;
}
/**
 * @brief I2C disable.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_disable(I2C_TypeDef * i2c)
{
    i2c->CTR =0x0;
}
/**
 * @brief send start and write cmd to slave.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_send_start_write_cmd(I2C_TypeDef * i2c)
{
    i2c->CR_SR=0x90;
}
/**
 * @brief send stop cmd.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_send_stop_cmd(I2C_TypeDef * i2c)
{
    i2c->CR_SR=0x40;;
}
/**
 * @brief I2C interruput enable.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_enable_int(I2C_TypeDef * i2c)
{
    i2c->CTR|=0x1<<6;
}

/**
 * @brief Send ack information.
 * @param i2c: I2C device.
 * @param cfg: =0, ACK; =1, NACK.
 * @return This function has no return.
 */
void i2c_send_ack(I2C_TypeDef * i2c,I2C_ACK_CONFIG cfg)
{
    i2c->CR_SR =cfg;
}






