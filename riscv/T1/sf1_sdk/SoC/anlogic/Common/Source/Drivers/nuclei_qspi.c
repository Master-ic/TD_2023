
#include "nuclei.h"
#include "nuclei_qspi.h"


/*!
    \brief      initialize the parameters of SPI struct with the default values
    \param[in]  spi_struct: SPI parameter stuct
    \param[out] none
    \retval     none
*/
void qspi_struct_para_init(qspi_parameter_struct* qspi_struct)
{    
    /* set the SPI struct with the default values */
    qspi_struct->sckdiv = 5;
    qspi_struct->csid = 1;
    qspi_struct->sckcs = 5;
    qspi_struct->cssck = 2;
    qspi_struct->intercs = 2;
    qspi_struct->len = 4;   
    qspi_struct->dir = 1;
    qspi_struct->csid = 1;
    qspi_struct->endian = 1;
    qspi_struct->proto = 2;              
}

/*!
    \brief      initialize SPI parameter
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[in]  spi_struct: SPI parameter initialization stuct members of the structure 
                            and the member values are shown as below:
                  device_mode: SPI_MASTER, SPI_SLAVE
                  trans_mode: SPI_TRANSMODE_FULLDUPLEX, SPI_TRANSMODE_RECEIVEONLY,
                              SPI_TRANSMODE_BDRECEIVE, SPI_TRANSMODE_BDTRANSMIT
                  frame_size: SPI_FRAMESIZE_16BIT, SPI_FRAMESIZE_8BIT
                  nss: SPI_NSS_SOFT, SPI_NSS_HARD
                  endian: SPI_ENDIAN_MSB, SPI_ENDIAN_LSB
                  clock_polarity_phase: SPI_CK_PL_LOW_PH_1EDGE, SPI_CK_PL_HIGH_PH_1EDGE
                                        SPI_CK_PL_LOW_PH_2EDGE, SPI_CK_PL_HIGH_PH_2EDGE
                  prescale: SPI_PSC_n (n=2,4,8,16,32,64,128,256)
    \param[out] none
    \retval     none
*/
void qspi_init(uint32_t qspi_periph, qspi_parameter_struct* qspi_struct)
{     
    uint32_t reg = 0U;
    QSPI_SCKDIV(qspi_periph) = qspi_struct->sckdiv;
    QSPI_CSID(qspi_periph) = qspi_struct->csid;
    QSPI_SCKMODE(qspi_periph) = qspi_struct->sckmode;
    QSPI_DELAY1(qspi_periph) = qspi_struct->intercs;
    reg = qspi_struct->cssck;
    reg |= (qspi_struct->sckcs)<<16;
    QSPI_DELAY0(qspi_periph) = reg;

    reg = qspi_struct->proto;
    reg |= (qspi_struct->endian)<<2;
    reg |= (qspi_struct->dir)<<3;
    reg |= (qspi_struct->len)<<16;
    QSPI_FMT(qspi_periph) = reg;    
}

FlagStatus qspi_flag_get(qspi_flag_enum flag)
{
    /* get the QSPI flag */
    if(RESET != (QSPI_REG_VAL(flag) & BIT(QSPI_BIT_POS(flag)))){
        return SET;
    }else{
        return RESET;
    }
}
/*!
    \brief      enable SPI
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_sckdiv_cfg(uint32_t qspi_periph, uint32_t div)
{
    QSPI_SCKDIV(qspi_periph) = div;
}

/*!
    \brief      enable SPI
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_sckmode_cfg(uint32_t qspi_periph,uint32_t sckmode)
{
    QSPI_SCKMODE(qspi_periph) = sckmode;
}


void qspi_csmode_cfg(uint32_t qspi_periph,CSMODE csmode)
{
    QSPI_SCMODE(qspi_periph) |=  csmode;
}


/*!
    \brief      disable SPI 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_csid_cfg(uint32_t qspi_periph,uint32_t csid)
{
    QSPI_CSID(qspi_periph) = csid;
}

/*!
    \brief      disable SPI 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_spi_delay0_cfg(uint32_t qspi_periph,uint32_t sckcs, uint32_t cssck)
{
    uint32_t tmp = 0;
    tmp |= (sckcs<<16);
    tmp |= cssck;
    QSPI_DELAY0(qspi_periph) = tmp;
}

/*!
    \brief      disable SPI 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_spi_delay1_cfg(uint32_t qspi_periph,uint32_t intercs)
{
    QSPI_DELAY0(qspi_periph) = intercs;
}

uint32_t qspi_spi_status(uint32_t qspi_periph)
{
    if(QSPI_STATUS(qspi_periph))
        return QSPI_STATUS_TIP_BUSY;
    else
        return QSPI_STATUS_TIP_IDLE;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
uint32_t qspi_txdata_txtip_get(uint32_t qspi_periph)
{
    if((QSPI_TXDATA(qspi_periph)) & 0x80000000)
        return SET;
    else
        return RESET;    
}

/*!
    \brief      USART transmit data function
    \param[in]  usart_periph: USARTx(x=0,1,2)/UARTx(x=3,4)
    \param[in]  data: data of transmission 
    \param[out] none
    \retval     none
*/
void qspi_data_transmit(uint32_t qspi_periph, uint8_t data)
{
    QSPI_TXDATA(qspi_periph)=data;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
uint32_t qspi_rxdata_rxtip_get(uint32_t qspi_periph)
{
    if((QSPI_RXDATA(qspi_periph)) & 0x80000000)
        return SET;
    else
        return RESET;    
}


/*!
    \brief      SPI receive data function
    \param[in]  usart_periph: USARTx(x=0,1,2)/UARTx(x=3,4)
    \param[out] none
    \retval     data of received
*/
uint8_t qspi_data_receive(uint32_t qspi_periph)
{
    return (uint8_t)(GET_BITS(QSPI_RXDATA(qspi_periph), 0U, 8U));
}

/*!
    \brief      enable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_fctrl_flashxip_enable(uint32_t qspi_periph)
{
    QSPI_FCTRL(qspi_periph) |= (uint32_t)QSPI_FCTRL_FEN;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_fctrl_flashxip_disable(uint32_t qspi_periph)
{
    QSPI_FCTRL(qspi_periph) &= (uint32_t)(~QSPI_FCTRL_FEN);
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_cmd_enable(uint32_t qspi_periph)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_CMDEN);
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_cmd_disable(uint32_t qspi_periph)
{
    QSPI_FFMT(qspi_periph) |= (uint32_t)QSPI_FFMT_CMDEN;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_addr_len_cfg(uint32_t qspi_periph, uint32_t len)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_ADDRLEN);
    QSPI_FFMT(qspi_periph) |= len;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_pad_cnt_cfg(uint32_t qspi_periph, uint32_t cnt)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_PADCNT);
    QSPI_FFMT(qspi_periph) |= cnt;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_cmd_proto_cfg(uint32_t qspi_periph, uint32_t proto)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_CMDPROTO);
    QSPI_FFMT(qspi_periph) |= proto;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_addr_proto_cfg(uint32_t qspi_periph, uint32_t proto)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_ADDRPROTO);
    QSPI_FFMT(qspi_periph) |= proto;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_data_proto_cfg(uint32_t qspi_periph, uint32_t proto)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_DATAPROTO);
    QSPI_FFMT(qspi_periph) |= proto;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_cmd_code(uint32_t qspi_periph, uint32_t cmd)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_CMDCODE);
    QSPI_FFMT(qspi_periph) |= cmd;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_pad_code(uint32_t qspi_periph, uint32_t pad)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~QSPI_FFMT_PADCODE);
    QSPI_FFMT(qspi_periph) |= pad;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_data_endian_msb(uint32_t qspi_periph)
{
    QSPI_FFMT(qspi_periph) &= (uint32_t)(~ QSPI_FFMT_DATAENDIA);
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt_data_endian_lsb(uint32_t qspi_periph)
{
    QSPI_FFMT(qspi_periph) |= (uint32_t)QSPI_FFMT_DATAENDIA;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt1_wpad_cnt_cfg(uint32_t qspi_periph, uint32_t cnt)
{
    QSPI_FFMT1(qspi_periph) &= (uint32_t)(~QSPI_FFMT1_WPADCNT);
    QSPI_FFMT1(qspi_periph) |= cnt;
}

/*!
    \brief      disable SPI NSS output 
    \param[in]  spi_periph: SPIx(x=0,1,2)
    \param[out] none
    \retval     none
*/
void qspi_ffmt1_wcmd_code(uint32_t qspi_periph, uint32_t cmd)
{
    QSPI_FFMT1(qspi_periph) &= (uint32_t)(~QSPI_FFMT1_WCMDCODE);
    QSPI_FFMT1(qspi_periph) |= cmd;
}
