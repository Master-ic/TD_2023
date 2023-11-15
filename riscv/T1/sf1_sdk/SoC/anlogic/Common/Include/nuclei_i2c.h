/**
 ****************************************************************************************
 * @defgroup I2C
 * @ingroup DRIVERS
 * @brief I2C Drivers.
 *        Functions specified for I2C.
 *
 * @{
 ****************************************************************************************
 */

#ifndef NUCLEI_I2C_H
#define NUCLEI_I2C_H

#include "nuclei.h"

#define I2C_WR_MODE_MASK    BIT(0)
#define I2C_ADDRESS_OFS       1
#define I2C_SEND_WRITE_CMD  BIT(7)

typedef enum i2c_ack_config{
    I2C_ACK  =BIT(3),
    I2C_NACK = ~BIT(3),
}I2C_ACK_CONFIG;

typedef enum i2c_wr_mode {
    I2C_WRITE = 0,
    I2C_READ = 1,
} I2C_WR_MODE;


typedef enum i2c_flag {
    RxACK = BIT(7),
    BUSY = BIT(6),
    AL = BIT(5),
    TIP = BIT(1),
    IF = BIT(0),
} I2C_FLAG;

/**
 * @brief I2C data transmitte.
 * @param i2c: I2C device.
 * @param data: data to be transmitted.
 * @return This function has no return.
 */
void i2c_data_transmit(I2C_TypeDef * i2c,uint8_t data);
/**
 * @brief I2C flag check.
 * @param i2c: I2C device.
 * @param flag: I2C state flag.
 * @return I2C state flag.
 */
uint32_t i2c_flag_get(I2C_TypeDef * i2c,I2C_FLAG flag);

/**
 * @brief I2C data receive.
 * @param i2c: I2C device.
 * @return RX register value.
 */
uint8_t i2c_data_receive(I2C_TypeDef * i2c);
/**
 * @brief I2C initial.
 * @param i2c: I2C device.
 * @param PRER: I2C Prescaler value.
 * @param trise: scl delay register.
 * @param fltr: filter register.
 * @return This function has no return.
 */
void i2c_init(I2C_TypeDef * i2c,uint16_t PRER,uint8_t trise,uint8_t fltr);
/**
 * @brief I2C slave device address and R/W mode config.
 * @param i2c: I2C device.
 * @param address: slave device address.
 * @param mode: R/W mode.
 * @return This function has no return.
 */
void i2c_mode_addr_config(I2C_TypeDef * i2c,uint8_t address,I2C_WR_MODE mode);

/**
 * @brief Stop I2C data transmitting.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_close_transmit(I2C_TypeDef * i2c);
/**
 * @brief Stop I2C data receiving.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_close_receive(I2C_TypeDef * i2c);
/**
 * @brief I2C enable.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_enable(I2C_TypeDef * i2c);
/**
 * @brief I2C disable.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_disable(I2C_TypeDef * i2c);
/**
 * @brief send start and write cmd to slave.
 * @param i2c: I2C device.
 * @return I2C state flag.
 */
void i2c_send_start_write_cmd(I2C_TypeDef * i2c);
/**
 * @brief I2C interruput enable.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_enable_int(I2C_TypeDef * i2c);
/**
 * @brief Send ack information.
 * @param i2c: I2C device.
 * @param cfg: =0, ACK; =1, NACK.
 * @return This function has no return.
 */
void i2c_send_ack(I2C_TypeDef * i2c,I2C_ACK_CONFIG cfg);
/**
 * @brief I2C data write to TX register.
 * @param i2c: I2C device.
 * @param data: data to be write.
 * @return This function has no return.
 */
void i2c_data_write(I2C_TypeDef * i2c,uint8_t data);
/**
 * @brief Read I2C data.
 * @param i2c: I2C device.
 * @return I2C RX data.
 */
uint8_t i2c_data_read(I2C_TypeDef * i2c);
/**
 * @brief send stop cmd.
 * @param i2c: I2C device.
 * @return This function has no return.
 */
void i2c_send_stop_cmd(I2C_TypeDef * i2c);

#endif /* _NUCLEI_I2C_H */