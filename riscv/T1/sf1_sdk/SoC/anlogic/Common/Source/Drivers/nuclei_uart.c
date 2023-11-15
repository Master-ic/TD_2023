#include "nuclei.h"
#include "nuclei_uart.h"

/*!
    \brief  uart initialize
    \param  uart: uart parameter stuct
    \param  baudrate: uart buadrate
    \param  bit_length: bit length (5/6/7/8/9)
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_init(UART_TypeDef *uart, uint32_t baudrate,UART_BIT_LENGTH bit_length)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->DIV = SystemCoreClock / ((misc_get_clock_divide()+1)*baudrate) - 1;
    uart->TXCTRL |= UART_TXEN;
    uart->RXCTRL |= UART_RXEN;
    uart->SETUP  &= ~UART_SETUP_BITLEN_MASK;
    uart->SETUP  |= (bit_length<<UART_SETUP_BITLEN_OFS) & UART_SETUP_BITLEN_MASK;
    return 0;
}

/*!
    \brief  uart stop bit config
    \param  uart: uart parameter stuct
    \param  stopbit: stop bit (1/2/0.5/1.5)
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_config_stopbit(UART_TypeDef *uart, UART_STOP_BIT stopbit)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->TXCTRL &= ~(UART_TXCTRL_NSTOP_MASK);
    uart->TXCTRL |= (stopbit << UART_TXCTRL_NSTOP_OFS);
    return 0;
}

/*!
    \brief  uart TXFIFO transmitte
    \param  uart: uart parameter stuct
    \param  val: value of TXFIFO
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_write(UART_TypeDef *uart, uint8_t val)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    while (uart->TXFIFO & UART_TXFIFO_FULL);
    uart->TXFIFO = val & 0xFF ;
    return 0;
}

/*!
    \brief  uart RXFIFO receive
    \param  uart: uart parameter stuct
    \retval RXFIFO value
*/
uint8_t uart_read(UART_TypeDef *uart)
{
    uint32_t reg;
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    do {
        reg = uart->RXFIFO;
    }
    while (reg & UART_RXFIFO_EMPTY);
    return (uint8_t)(reg & 0xFF);
}

/*!
    \brief  uart TXFIFO transmitte (9bit)
    \param  uart: uart parameter stuct
    \param  val: value of TXFIFO
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_write_9bit(UART_TypeDef *uart, uint16_t val)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    while (uart->TXFIFO & UART_TXFIFO_FULL);
    uart->TXFIFO = val&0x1FF ;
    return 0;
}

/*!
    \brief  uart RXFIFO receive (9bit)
    \param  uart: uart parameter stuct
    \retval RXFIFO value
*/
uint16_t uart_read_9bit(UART_TypeDef *uart)
{
    uint32_t reg;
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    do {
        reg = uart->RXFIFO;
    }
    while (reg & UART_RXFIFO_EMPTY);
    return (uint16_t)(reg & 0x1FF);
}

/*!
    \brief  set uart TX interrupt threshold value.
    \param  uart: uart parameter stuct
    \param  watermark: threshold value
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_set_tx_watermark(UART_TypeDef *uart, uint32_t watermark)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    watermark = (watermark << UART_TXCTRL_TXCNT_OFS) & UART_TXCTRL_TXCNT_MASK;
    uart->TXCTRL |= watermark;
    return 0;
}

/*!
    \brief  uart TX interrupt enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_txint(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->IE |= UART_IE_TXIE_MASK;
    return 0;
}

/*!
    \brief  uart TX interrupt disable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_disable_txint(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->IE &= ~UART_IE_TXIE_MASK;
    return 0;
}

/*!
    \brief  set uart RX interrupt threshold value.
    \param  uart: uart parameter stuct
    \param  watermark: threshold value
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_set_rx_watermark(UART_TypeDef *uart, uint32_t watermark)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    watermark = (watermark << UART_RXCTRL_RXCNT_OFS) & UART_RXCTRL_RXCNT_MASK;
    uart->RXCTRL |= watermark;
    return 0;
}

/*!
    \brief  uart RX interrupt enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_rxint(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->IE |= UART_IE_RXIE_MASK;
    return 0;
}

/*!
    \brief  uart RX interrupt disable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_disable_rxint(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->IE &= ~UART_IE_RXIE_MASK;
    return 0;
}

/*!
    \brief  uart RX busy status check.
    \param  uart: uart parameter stuct
    \retval 0/1,if uart!=null; otherwise -1;
*/
int32_t uart_get_rxbusy(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    return (uart->STATUS & UART_STATUS_RXBUSY_MASK) ;
}

/*!
    \brief  uart TX busy status check.
    \param  uart: uart parameter stuct
    \retval 
*/
int32_t uart_get_txbusy(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    return (uart->STATUS & UART_STATUS_TXBUSY_MASK) ;
}

/*!
    \brief  uart parity bit enable.
    \param  uart: uart parameter stuct
    \retval 
*/
int32_t uart_parity_en(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->SETUP |=UART_SETUP_PARITYEN_MASK;
}

/*!
    \brief  uart parity check mode selection.
    \param  uart: uart parameter stuct
    \param  parit_sel: 0-even; 1-odd;
    \retval 
*/
int32_t uart_parity_sel(UART_TypeDef *uart,UART_PARITY_BIT parit_sel)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->SETUP |=((parit_sel<<UART_SETUP_PARITYSEL_OFS )& UART_SETUP_PARITYSEL_MASK);
}

int32_t uart_stopclean_fifo(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->SETUP &= ~UART_SETUP_CLEANFIFO_MASK;
    return 0;
}

/*!
    \brief  clean uart fifo.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_clean_fifo(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->SETUP |= UART_SETUP_CLEANFIFO_MASK;
    uart->SETUP &= ~UART_SETUP_CLEANFIFO_MASK;
    return 0;
}

/*!
    \brief  uart rxfifo overflow error check.
    \param  uart: uart parameter stuct
    \retval 0,ok; 1,error;
*/
int32_t uart_get_error_overflow(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    return (uart->ERROR & UART_ERROR_OVERFLOW_MASK);
    
}

/*!
    \brief  uart parity error check.
    \param  uart: uart parameter stuct
    \retval 0,ok; 1,error;
*/
int32_t uart_get_error_parity(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    return (uart->ERROR & UART_ERROR_PARITY_MASK);
}

/*!
    \brief  uart rxfifo overflow error interruput enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_ov_irq(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    uart->IRQ_EN |=UART_ERROR_OVERFLOW_MASK;
    return 0;
    
}

/*!
    \brief  uart parity error interruput enable.
    \param  uart: uart parameter stuct
    \retval 0,if uart!=null; otherwise -1;
*/
int32_t uart_enable_err_irq(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
     (uart->IRQ_EN |= UART_ERROR_PARITY_MASK);
     return 0;
}

/*!
    \brief  uart TX interruput pend flag.
    \param  uart: uart parameter stuct
    \retval flag,if uart!=null; otherwise -1;
*/
int32_t uart_get_flag_txip(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    return (uart->IP& UART_IP_TXIP_MASK);
    
}

/*!
    \brief  uart RX interruput pend flag.
    \param  uart: uart parameter stuct
    \retval flag,if uart!=null; otherwise -1;
*/
int32_t uart_get_flag_rxip(UART_TypeDef *uart)
{
    if (__RARELY(uart == NULL)) {
        return -1;
    }
    return (uart->IP & UART_IP_RXIP_MASK);
}
