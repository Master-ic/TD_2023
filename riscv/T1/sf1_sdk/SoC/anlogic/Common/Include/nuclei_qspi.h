
#ifndef NUCLEI_QSPI_H
#define NUCLEI_QSPI_H

#include "nuclei.h"


/* SPIx(x=0,1,2) definitions */
// #define QSPI_BASE                         QSPI_BASE
#define QSPI0                          QSPI0_BASE
#define QSPI                          QSPI_BASE

#define SPI_REG_SCKDIV          0x00
#define SPI_REG_SCKMODE         0x04
#define SPI_REG_FORCE           0x0c
#define SPI_REG_CSID            0x10
#define SPI_REG_CSDEF           0x14
#define SPI_REG_CSMODE          0x18

#define SPI_REG_DCSSCK          0x28
#define SPI_REG_DSCKCS          0x2a
#define SPI_REG_DINTERCS        0x2c
#define SPI_REG_DINTERXFR       0x2e

#define SPI_REG_FMT             0x40
#define SPI_REG_TXFIFO          0x48
#define SPI_REG_RXFIFO          0x4c
#define SPI_REG_TXMARK          0x50
#define SPI_REG_RXMARK          0x54

#define SPI_REG_FCTRL           0x60
#define SPI_REG_FFMT            0x64

#define SPI_REG_IE              0x70
#define SPI_REG_IP              0x74
#define SPI_REG_STATUS          0x7C



/* SPI registers definitions */
#define QSPI_SCKDIV(spix)                REG32((spix) + 0x00U)                   /*!< SPI control register 0 */
#define QSPI_SCKMODE(spix)               REG32((spix) + 0x04U)                   /*!< SPI control register 1*/
#define QSPI_CSID(spix)                  REG32((spix) + 0x10U)                   /*!< SPI status register */
#define QSPI_SCMODE(spix)                REG32((spix) + 0x18U)                   /*!< SPI control register 1*/
#define QSPI_DELAY0(spix)                REG32((spix) + 0x28U)                   /*!< SPI data register */
#define QSPI_DELAY1(spix)                REG32((spix) + 0x2CU)                   /*!< SPI CRC polynomial register */
#define QSPI_FMT(spix)                   REG32((spix) + 0x40U)                   /*!< SPI receive CRC register */
#define QSPI_TXDATA(spix)                REG32((spix) + 0x48U)                   /*!< SPI transmit CRC register */
#define QSPI_RXDATA(spix)                REG32((spix) + 0x4CU)                   /*!< SPI I2S control register */
#define QSPI_FCTRL(spix)                 REG32((spix) + 0x60U)                   /*!< SPI I2S clock prescaler register */
#define QSPI_FFMT(spix)                  REG32((spix) + 0x64U)                   /*!< SPI transmit CRC register */
#define QSPI_FFMT1(spix)                 REG32((spix) + 0x78U)                   /*!< SPI I2S control register */
#define QSPI_STATUS(spix)                REG32((spix) + 0x7CU)                   /*!< SPI I2S clock prescaler register */
#define QSPI_TXMARK(spix)                REG32((spix) + 0x50U)                   /*!< SPI I2S clock prescaler register */
#define QSPI_RXMARK(spix)                REG32((spix) + 0x54U)                   /*!< SPI I2S clock prescaler register */
#define QSPI_IE(spix)                    REG32((spix) + 0x70U)                   /*!< SPI I2S clock prescaler register */
#define QSPI_IP(spix)                    REG32((spix) + 0x74U)                   /*!< SPI I2S clock prescaler register */


/* bits definitions */
/* QSPI_SCKDIV */
#define QSPI_SCKDIV_DIV                  BITS(0,11)                              /*!< clock phase selection*/

/* QSPI_SCKMODE */
#define QSPI_SCKMODE_PHA                 BIT(0)                                  /*!< receive buffer dma enable */
#define QSPI_SCKMODE_POL                 BIT(1)                                  /*!< transmit buffer dma enable */

/* QSPI_CSID */
#define QSPI_CSID_CSID                   BITS(0,1)                               /*!< receive buffer not empty */

/* QSPI_DELAY0 */
#define QSPI_DELAY0_CSSCK                BITS(0,7)                               /*!< receive buffer dma enable */
#define QSPI_DELAY0_SCKCS                BIT(16,23)                              /*!< transmit buffer dma enable */

/* QSPI_DELAY1 */
#define QSPI_DELAY1_INTERCS              BIT(0)                                  /*!< receive buffer dma enable */

/* QSPI_FMT */
//#define QSPI_FMT_PROTO                   BITS(0,1)                               /*!< channel length */
//#define QSPI_FMT_ENDIAN                  BIT(2)                                  /*!< data length */
#define QSPI_FMT_DIRE                    BIT(3)                                  /*!< idle state clock polarity */
//#define QSPI_FMT_LEN                     BITS(16,19)                             /*!< I2S standard selection */

/* QSPI_STATUS */
#define QSPI_STATUS_TIP                  BIT(0)                                  /*!< data transfer register */

/* QSPI_TXDATA */
#define QSPI_TXDATA_TXDATA               BITS(0,7)                               /*!< CRC polynomial value */
#define QSPI_TXDATA_TXTIP                BITS(31)                                /*!< CRC polynomial value */

/* QSPI_RXDATA */
#define QSPI_RXDATA_TXDATA               BITS(0,7)                               /*!< CRC polynomial value */
#define QSPI_RXDATA_TXTIP                BITS(31)                                /*!< CRC polynomial value */


/* QSPI_FCTRL */
#define QSPI_FCTRL_FEN                   BIT(0)                                  /*!< RX CRC value */
#define QSPI_FCTRL_FWEN                  BIT(2)                                  /*!< RX CRC value */
#define QSPI_FCTRL_FBURSTEN              BIT(3)                                  /*!< RX CRC value */

/* QSPI_FFMT */
#define QSPI_FFMT_CMDEN                  BIT(0)                                  /*!< channel length */
#define QSPI_FFMT_ADDRLEN                BITS(1,3)                               /*!< data length */
#define QSPI_FFMT_PADCNT                 BITS(4,7)                               /*!< idle state clock polarity */
#define QSPI_FFMT_CMDPROTO               BITS(8,9)                               /*!< I2S standard selection */
#define QSPI_FFMT_ADDRPROTO              BITS(10,11)                             /*!< PCM frame synchronization mode */
#define QSPI_FFMT_DATAPROTO              BITS(12,13)                             /*!< I2S operation mode */
#define QSPI_FFMT_DATAENDIA              BIT(14)                                 /*!< I2S enable */
#define QSPI_FFMT_CMDCODE                BITS(16,23)                             /*!< I2S mode selection */
#define QSPI_FFMT_PADCODE                BITS(24,31)                             /*!< I2S mode selection */

/* QSPI_FFMT1 */
#define QSPI_FFMT1_WCMDCODE              BITS(0,7)                               /*!< dividing factor for the prescaler */
#define QSPI_FFMT1_WPADCNT               BITS(8,11)                              /*!< odd factor for the prescaler */

/* constants definitions */
/* SPI and I2S parameter struct definitions */
typedef struct
{
    uint32_t sckdiv;                                /*!< SPI clock divider */
    uint32_t sckmode;                               /*!< SPI clock mode */
    uint32_t csid;                                  /*!< SPI CSID */
    uint32_t intercs;                               /*!< SPI transtype */
    uint32_t sckcs;                                 /*!< SPI frame size */
    uint32_t cssck;                                 /*!< SPI NSS control by handware or software */
    uint32_t endian;                                /*!< SPI big endian or little endian */
    uint32_t len;
    uint32_t dir;
    uint32_t proto;
}qspi_parameter_struct;

typedef struct
{    
    uint32_t pad_code;
    uint32_t cmd_code;
    uint32_t data_endian;
    uint32_t data_proto;
    uint32_t addr_proto;
    uint32_t cmd_proto;
    uint32_t pad_cnt;
    uint32_t addr_len;
    uint32_t cmd_en;
    uint32_t wpad_cnt;
    uint32_t wcmd_code;
}qspi_cmd_struct;

/* SPI transmit type */
#define QSPI_SCKMODE_CPOL_EN           ((uint32_t)0x00000001U)                 /*!< SPI receive and send data at fullduplex communication */
#define QSPI_SCKMODE_CPHA_EN           ((uint32_t)0x00000002U)                 /*!< SPI receive and send data at fullduplex communication */

/* I2S standard */
#define QSPI_CSID_SS(regval)           (BITS(0,1) & ((uint32_t)(regval)))
#define QSPI_CSID_SS0                  QSPI_CSID(0)                          /*!< I2S phillips standard */
#define QSPI_CSID_SS1                  QSPI_CSID(1)                          /*!< I2S MSB standard */
#define QSPI_CSID_SS2                  QSPI_CSID(2)                          /*!< I2S LSB standard */
#define QSPI_CSID_SS3                  QSPI_CSID(3)                          /*!< I2S PCM short standard */

#define QSPI_FMT_PROTO(regval)         (BITS(0,1) & ((uint32_t)(regval)))
#define QSPI_FMT_PROTO_SINGLE          QSPI_FMT_PROTO(0)                     /*!< I2S phillips standard */
#define QSPI_FMT_PROTO_DUAL            QSPI_FMT_PROTO(1)                     /*!< I2S MSB standard */
#define QSPI_FMT_PROTO_QUAD            QSPI_FMT_PROTO(2)                     /*!< I2S LSB standard */

#define QSPI_FMT_ENDIAN(regval)        (BIT(2) & ((uint32_t)(regval) << 2))
#define QSPI_FMT_ENDIAN_MSB            QSPI_FMT_ENDIAN(0)                    /*!< I2S data length is 16 bit and channel length is 16 bit */
#define QSPI_FMT_ENDIAN_LSB            QSPI_FMT_ENDIAN(1)                    /*!< I2S data length is 16 bit and channel length is 32 bit */

#define QSPI_FMT_DIR(regval)           (BIT(3) & ((uint32_t)(regval) << 3))
#define QSPI_FMT_DIR_RX                QSPI_FMT_DIR(0)                       /*!< I2S data length is 16 bit and channel length is 16 bit */
#define QSPI_FMT_DIR_TX                QSPI_FMT_DIR(1)                       /*!< I2S data length is 16 bit and channel length is 32 bit */

#define QSPI_FMT_LEN(regval)           (BITS(16,19) & ((uint32_t)(regval) << 16))
#define QSPI_FMT_LEN0                  QSPI_FMT_LEN(0)                     /*!< I2S phillips standard */
#define QSPI_FMT_LEN1                  QSPI_FMT_LEN(1)                     /*!< I2S MSB standard */
#define QSPI_FMT_LEN2                  QSPI_FMT_LEN(2)                     /*!< I2S LSB standard */
#define QSPI_FMT_LEN3                  QSPI_FMT_LEN(3)                     /*!< I2S phillips standard */
#define QSPI_FMT_LEN4                  QSPI_FMT_LEN(4)                     /*!< I2S MSB standard */
#define QSPI_FMT_LEN5                  QSPI_FMT_LEN(5)                     /*!< I2S LSB standard */
#define QSPI_FMT_LEN6                  QSPI_FMT_LEN(6)                     /*!< I2S phillips standard */
#define QSPI_FMT_LEN7                  QSPI_FMT_LEN(7)                     /*!< I2S MSB standard */
#define QSPI_FMT_LEN8                  QSPI_FMT_LEN(8)                     /*!< I2S MSB standard */

#define QSPI_STATUS_TIP_IDLE           ((uint32_t)0x00000000U)                 /*!< SPI receive and send data at fullduplex communication */
#define QSPI_STATUS_TIP_BUSY           ((uint32_t)0x00000001U)


/* define the peripheral clock enable bit position and its register index offset */
#define QSPI_REGIDX_BIT(regidx, bitpos)      (((uint32_t)(regidx) << 6) | (uint32_t)(bitpos))
#define QSPI_REG_VAL(periph)                 (REG32(QSPI_BASE + ((uint32_t)(periph) >> 6)))
#define QSPI_BIT_POS(val)                    ((uint32_t)(val) & 0x1FU)

/* register offset */
/* peripherals enable */
#define STATUS_REG_OFFSET               0x7CU                     /*!< AHB enable register offset */
#define TXDATA_REG_OFFSET               0x48U                     /*!< APB1 enable register offset */
#define RXDATA_REG_OFFSET               0x4CU                     /*!< APB2 enable register offset */

typedef enum csmode{
    SPI_AUTO = 0,
    SPI_HOLD = 2,
    SPI_OFF  = 3,
}CSMODE;
/* clock stabilization and peripheral reset flags */
typedef enum {
	/* clock stabilization flags */
	QSPI_FLAG_TIP = QSPI_REGIDX_BIT(STATUS_REG_OFFSET, 0U),       /*!< IRC8M stabilization flags */
	QSPI_FLAG_TXTIP = QSPI_REGIDX_BIT(TXDATA_REG_OFFSET, 31U),      /*!< HXTAL stabilization flags */
	QSPI_FLAG_RXTIP = QSPI_REGIDX_BIT(RXDATA_REG_OFFSET, 31U),        /*!< PLL stabilization flags */
} qspi_flag_enum;

void qspi_csmode_cfg(uint32_t qspi_periph,CSMODE csmode);
void qspi_sckmode_cfg(uint32_t qspi_periph,uint32_t sckmode);
/* function declarations */
/* reset SPI and I2S */
void qspi_deinit(uint32_t qspi_periph);
/* initialize the parameters of SPI struct with the default values */
void qspi_struct_para_init(qspi_parameter_struct* qspi_struct);
/* initialize SPI parameter */
void qspi_init(uint32_t qspi_periph, qspi_parameter_struct* qspi_struct);
/* enable SPI */
void qspi_sckdiv_cfg(uint32_t qspi_periph, uint32_t div);
/* disable SPI */
void qspi_sckmode_pol_enable(uint32_t qspi_periph,uint32_t sckmode);

/* disable I2S */
void qspi_csid_cfg(uint32_t qspi_periph,uint32_t csid);

/* NSS functions */
/* enable SPI NSS output */
void qspi_spi_delay0_cfg(uint32_t qspi_periph,uint32_t sckcs, uint32_t cssck);
/* disable SPI NSS output */
void qspi_spi_delay1_cfg(uint32_t qspi_periph,uint32_t intercs);
/* SPI NSS pin high level in software mode */
uint32_t qspi_spi_status(uint32_t qspi_periph);
/* SPI NSS pin low level in software mode */
void qspi_fctrl_flashxip_enable(uint32_t qspi_periph);

void qspi_fctrl_flashxip_disable(uint32_t qspi_periph);

uint32_t qspi_txdata_txtip_get(uint32_t qspi_periph);

void qspi_data_transmit(uint32_t qspi_periph, uint8_t data);

uint32_t qspi_rxdata_rxtip_get(uint32_t qspi_periph);

uint8_t qspi_data_receive(uint32_t qspi_periph);

void qspi_ffmt_cmd_enable(uint32_t qspi_periph);

void qspi_ffmt_cmd_disable(uint32_t qspi_periph);

void qspi_ffmt_addr_len_cfg(uint32_t qspi_periph, uint32_t len);

void qspi_ffmt_pad_cnt_cfg(uint32_t qspi_periph, uint32_t cnt);

void qspi_ffmt_cmd_proto_cfg(uint32_t qspi_periph, uint32_t proto);

void qspi_ffmt_addr_proto_cfg(uint32_t qspi_periph, uint32_t proto);

void qspi_ffmt_data_proto_cfg(uint32_t qspi_periph, uint32_t proto);

void qspi_ffmt_cmd_code(uint32_t qspi_periph, uint32_t cmd);

void qspi_ffmt_pad_code(uint32_t qspi_periph, uint32_t pad);

void qspi_ffmt_data_endian_msb(uint32_t qspi_periph);

void qspi_ffmt_data_endian_lsb(uint32_t qspi_periph);

void qspi_ffmt1_wpad_cnt_cfg(uint32_t qspi_periph, uint32_t cnt);

void qspi_ffmt1_wcmd_code(uint32_t qspi_periph, uint32_t cmd);

#endif /* NUCLEI_QSPI_H */
