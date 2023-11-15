/**
 ****************************************************************************************
 * @defgroup UART
 * @ingroup DRIVERS
 * @brief UART Drivers.
 *        Functions specified for UART.
 *
 * @{
 ****************************************************************************************
 */

#ifndef _NUCLEI_UART_H
#define _NUCLEI_UART_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Register offsets */
#define UART_REG_TXDATA         0x00
#define UART_REG_RXDATA         0x04
#define UART_REG_TXCTRL         0x08
#define UART_REG_RXCTRL         0x0c
#define UART_REG_IE             0x10
#define UART_REG_IP             0x14
#define UART_REG_DIV            0x18
#define UART_STATUS             0x1c
#define UART_SETUP              0x20
#define UART_ERROR              0x24
#define UART_IRQ_EN             0x28



/* TXCTRL register */
#define UART_TXEN               0x1
#define UART_TXWM(x)            (((x) & 0xffff) << 16)

/* RXCTRL register */
#define UART_RXEN               0x1
#define UART_RXWM(x)            (((x) & 0xffff) << 16)

/* IP register */
#define UART_IP_TXWM            0x1
#define UART_IP_RXWM            0x2

#define UART_TXFIFO_FULL        (1<<31)
#define UART_RXFIFO_EMPTY       (1<<31)

#define UART_TXCTRL_TXCNT_OFS   (16)
#define UART_TXCTRL_TXCNT_MASK  (0x7 << UART_TXCTRL_TXCNT_OFS)
#define UART_TXCTRL_TXEN_OFS    (0)
#define UART_TXCTRL_TXEN_MASK   (0x1 << UART_TXCTRL_TXEN_OFS)
#define UART_TXCTRL_NSTOP_OFS   (1)
#define UART_TXCTRL_NSTOP_MASK  (0x3 << UART_TXCTRL_NSTOP_OFS)

#define UART_RXCTRL_RXCNT_OFS   (16)
#define UART_RXCTRL_RXCNT_MASK  (0x7 << UART_RXCTRL_RXCNT_OFS)
#define UART_RXCTRL_RXEN_OFS    (0)
#define UART_RXCTRL_RXEN_MASK   (0x1 << UART_RXCTRL_RXEN_OFS)

#define UART_IE_TXIE_OFS        (0)
#define UART_IE_TXIE_MASK       (0x1 << UART_IE_TXIE_OFS)
#define UART_IE_RXIE_OFS        (1)
#define UART_IE_RXIE_MASK       (0x1 << UART_IE_RXIE_OFS)

#define UART_IP_TXIP_OFS        (0)
#define UART_IP_TXIP_MASK       (0x1 << UART_IP_TXIP_OFS)
#define UART_IP_RXIP_OFS        (1)
#define UART_IP_RXIP_MASK       (0x1 << UART_IP_RXIP_OFS)

#define UART_STATUS_RXBUSY_OFS  (0)
#define UART_STATUS_RXBUSY_MASK (0x1 << UART_STATUS_RXBUSY_OFS)   
#define UART_STATUS_TXBUSY_OFS  (1)  
#define UART_STATUS_TXBUSY_MASK (0x1 << UART_STATUS_TXBUSY_OFS) 

#define UART_SETUP_PARITYEN_OFS   (0)
#define UART_SETUP_PARITYEN_MASK  (0x1 << UART_SETUP_PARITYEN_OFS)
#define UART_SETUP_PARITYSEL_OFS  (1)
#define UART_SETUP_PARITYSEL_MASK (0x1 << UART_SETUP_PARITYSEL_OFS)
#define UART_SETUP_CLEANFIFO_OFS  (3)
#define UART_SETUP_CLEANFIFO_MASK (0x1 << UART_SETUP_CLEANFIFO_OFS)
#define UART_SETUP_BITLEN_OFS     (4)
#define UART_SETUP_BITLEN_MASK    (0x7 << UART_SETUP_BITLEN_OFS)

#define UART_ERROR_FLAG_RXOF_OFS (0)
#define UART_ERROR_FLAG_RXOF_MASK (0x1 << UART_ERROR_FLAG_RXOF_OFS)
#define UART_ERROR_FLAG_PARITY_OFS (1)
#define UART_ERROR_FLAG_PARITY_MASK (0x1 << UART_ERROR_FLAG_PARITY_OFS)

#define UART_ERROR_OVERFLOW_OFS (0)
#define UART_ERROR_OVERFLOW_MASK (0x1 << UART_ERROR_OVERFLOW_OFS)
#define UART_ERROR_PARITY_OFS (1)
#define UART_ERROR_PARITY_MASK (0x1 << UART_ERROR_PARITY_OFS)



typedef enum uart_stop_bit {
    UART_STOP_BIT_1 = 0,
    UART_STOP_BIT_2 = 1,    
    UART_STOP_BIT_0p5 = 2,
    UART_STOP_BIT_1p5 = 3
} UART_STOP_BIT;

typedef enum uart_pariy_bit {
    UART_EVEN_BIT = 0,
    UART_ODD_BIT = 1,
} UART_PARITY_BIT;


typedef enum uart_bit_length {
    UART_BIT_LENGTH_5 = 0 ,
    UART_BIT_LENGTH_6 = 1 ,
    UART_BIT_LENGTH_7 = 2 ,
    UART_BIT_LENGTH_8 = 3 ,
    UART_BIT_LENGTH_9 = 4 , 
} UART_BIT_LENGTH;

/*!
    \brief  uart initialize
    \param  uart: uart parameter stuct
    \param  baudrate: uart buadrate
    \param  bit_length: bit length (5/6/7/8/9)
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_init(UART_TypeDef *uart, uint32_t baudrate,UART_BIT_LENGTH bitlength);
/*!
    \brief  uart stop bit config
    \param  uart: uart parameter stuct
    \param  stopbit: stop bit (1/2/0.5/1.5)
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_config_stopbit(UART_TypeDef *uart, UART_STOP_BIT stopbit);
/*!
    \brief  uart TXFIFO transmitte
    \param  uart: uart parameter stuct
    \param  val: value of TXFIFO
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_write(UART_TypeDef *uart, uint8_t val);
/*!
    \brief  uart RXFIFO receive
    \param  uart: uart parameter stuct
    \retval RXFIFO value
*/
uint8_t uart_read(UART_TypeDef *uart);
/*!
    \brief  set uart TX interrupt threshold value.
    \param  uart: uart parameter stuct
    \param  watermark: threshold value
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_set_tx_watermark(UART_TypeDef *uart, uint32_t watermark);
/*!
    \brief  uart TX interrupt enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_txint(UART_TypeDef *uart);
/*!
    \brief  uart TX interrupt disable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_disable_txint(UART_TypeDef *uart);
/*!
    \brief  set uart RX interrupt threshold value.
    \param  uart: uart parameter stuct
    \param  watermark: threshold value
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_set_rx_watermark(UART_TypeDef *uart, uint32_t watermark);
/*!
    \brief  uart RX interrupt enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_rxint(UART_TypeDef *uart);
/*!
    \brief  uart RX interrupt disable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_disable_rxint(UART_TypeDef *uart);
/*!
    \brief  uart RX busy status check.
    \param  uart: uart parameter stuct
    \retval 0/1,if uart!=null; otherwise -1;
*/
int32_t uart_get_rxbusy(UART_TypeDef *uart);
/*!
    \brief  uart TX busy status check.
    \param  uart: uart parameter stuct
    \retval 
*/
int32_t uart_get_txbusy(UART_TypeDef *uart);

int32_t uart_stopclean_fifo(UART_TypeDef *uart);
/*!
    \brief  clean uart fifo.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_clean_fifo(UART_TypeDef *uart);
/*!
    \brief  uart rxfifo overflow error check.
    \param  uart: uart parameter stuct
    \retval 0,ok; 1,error;
*/
int32_t uart_get_error_overflow(UART_TypeDef *uart);
/*!
    \brief  uart parity error check.
    \param  uart: uart parameter stuct
    \retval 0,ok; 1,error;
*/
int32_t uart_get_error_parity(UART_TypeDef *uart);
/*!
    \brief  uart parity bit enable.
    \param  uart: uart parameter stuct
    \retval 
*/
int32_t uart_parity_en(UART_TypeDef *uart);
/*!
    \brief  uart parity check mode selection.
    \param  uart: uart parameter stuct
    \param  parit_sel: 0-even; 1-odd;
    \retval 
*/
int32_t uart_parity_sel(UART_TypeDef *uart,UART_PARITY_BIT parit_sel);

/*!
    \brief  uart rxfifo overflow error interruput enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_ov_irq(UART_TypeDef *uart);
/*!
    \brief  uart parity error interruput enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_err_irq(UART_TypeDef *uart);
/*!
    \brief  uart RXFIFO receive (9bit)
    \param  uart: uart parameter stuct
    \retval RXFIFO value
*/
uint16_t uart_read_9bit(UART_TypeDef *uart);
/*!
    \brief  uart TXFIFO transmitte (9bit)
    \param  uart: uart parameter stuct
    \param  val: value of TXFIFO
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_write_9bit(UART_TypeDef *uart, uint16_t val);
/*!
    \brief  uart RX interruput pend flag.
    \param  uart: uart parameter stuct
    \retval flag,if uart!=null; otherwise -1;
*/
int32_t uart_get_flag_rxip(UART_TypeDef *uart);
/*!
    \brief  uart TX interruput pend flag.
    \param  uart: uart parameter stuct
    \retval flag,if uart!=null; otherwise -1;
*/
int32_t uart_get_flag_txip(UART_TypeDef *uart);


#ifdef __cplusplus
}
#endif
#endif /* _HBIRD_UART_H */

