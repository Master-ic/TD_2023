/******************************************************************************
 * @file     Nuclei.h
 * @brief    NMSIS Core Peripheral Access Layer Header File for
 *           Nuclei HummingBird evaluation SoC which support Nuclei N/NX class cores
 * @version  V1.00
 * @date     22. Nov 2019
 ******************************************************************************/
/*
 * Copyright (c) 2019 Nuclei Limited. All rsights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __NUCLEI_H__
#define __NUCLEI_H__

#include <stddef.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup Nuclei
  * @{
  */


/** @addtogroup hbird
  * @{
  */


/** @addtogroup Configuration_of_NMSIS
  * @{
  */



/* =========================================================================================================================== */
/* ================                                Interrupt Number Definition                                ================ */
/* =========================================================================================================================== */

typedef enum IRQn
{
/* =======================================  Nuclei Core Specific Interrupt Numbers  ======================================== */

    Reserved0_IRQn            =   0,              /*!<  Internal reserved */
    Reserved1_IRQn            =   1,              /*!<  Internal reserved */
    Reserved2_IRQn            =   2,              /*!<  Internal reserved */
    SysTimerSW_IRQn           =   3,              /*!<  System Timer SW interrupt */
    Reserved3_IRQn            =   4,              /*!<  Internal reserved */
    Reserved4_IRQn            =   5,              /*!<  Internal reserved */
    Reserved5_IRQn            =   6,              /*!<  Internal reserved */
    SysTimer_IRQn             =   7,              /*!<  System Timer Interrupt */
    Reserved6_IRQn            =   8,              /*!<  Internal reserved */
    Reserved7_IRQn            =   9,              /*!<  Internal reserved */
    Reserved8_IRQn            =  10,              /*!<  Internal reserved */
    Reserved9_IRQn            =  11,              /*!<  Internal reserved */
    Reserved10_IRQn           =  12,              /*!<  Internal reserved */
    Reserved11_IRQn           =  13,              /*!<  Internal reserved */
    Reserved12_IRQn           =  14,              /*!<  Internal reserved */
    Reserved13_IRQn           =  15,              /*!<  Internal reserved */
    Reserved14_IRQn           =  16,              /*!<  Internal reserved */
    Reserved15_IRQn           =  17,              /*!<  Internal reserved */
    Reserved16_IRQn           =  18,              /*!<  Internal reserved */

/* ===========================================  hbird Specific Interrupt Numbers  ========================================= */
/* ToDo: add here your device specific external interrupt numbers. 19~1023 is reserved number for user. Maxmum interrupt supported
         could get from clicinfo.NUM_INTERRUPT. According the interrupt handlers defined in startup_Device.s
         eg.: Interrupt for Timer#1       eclic_tim1_handler   ->   TIM1_IRQn */
    UART0_IRQn           = 19,                /*!< Device Interrupt */
    I2C_IRQn           = 20,                /*!< Device Interrupt */
    QSPI0_IRQn             = 21,                /*!< Device Interrupt */
    QSPI_IRQn             = 22,                /*!< Device Interrupt */
    GPIO0_IRQn            = 23,                /*!< Device Interrupt */
    GPIO1_IRQn            = 24,                /*!< Device Interrupt */
    GPIO2_IRQn            = 25,                /*!< Device Interrupt */
    GPIO3_IRQn            = 26,                /*!< Device Interrupt */
    GPIO4_IRQn            = 27,                /*!< Device Interrupt */
    GPIO5_IRQn            = 28,                /*!< Device Interrupt */
    GPIO6_IRQn            = 29,                /*!< Device Interrupt */
    GPIO7_IRQn            = 30,                /*!< Device Interrupt */
    FPGA0_IRQn            = 31,                /*!< Device Interrupt */
    FPGA1_IRQn            = 32,                /*!< Device Interrupt */
    FPGA2_IRQn           = 33,                /*!< Device Interrupt */
    FPGA3_IRQn           = 34,                /*!< Device Interrupt */
    FPGA4_IRQn           = 35,                /*!< Device Interrupt */
    FPGA5_IRQn           = 36,                /*!< Device Interrupt */
    FPGA6_IRQn           = 37,                /*!< Device Interrupt */
    FPGA7_IRQn           = 38,                /*!< Device Interrupt */
    PPGA8_IRQn           = 39,                /*!< Device Interrupt */
    FPGA9_IRQn           = 40,                /*!< Device Interrupt */
    FPGA10_IRQn           = 41,                /*!< Device Interrupt */
    FPGA11_IRQn           = 42,                /*!< Device Interrupt */
    FPGA12_IRQn           = 43,                /*!< Device Interrupt */
    FPGA13_IRQn           = 44,                /*!< Device Interrupt */
    FPGA14_IRQn           = 45,                /*!< Device Interrupt */
    FPGA15_IRQn           = 46,                /*!< Device Interrupt */
    SOC_INT_MAX,
} IRQn_Type;

/* =========================================================================================================================== */
/* ================                                  Exception Code Definition                                ================ */
/* =========================================================================================================================== */

typedef enum EXCn {
/* =======================================  Nuclei N/NX Specific Exception Code  ======================================== */
    InsUnalign_EXCn          =   0,              /*!<  Instruction address misaligned */
    InsAccFault_EXCn         =   1,              /*!<  Instruction access fault */
    IlleIns_EXCn             =   2,              /*!<  Illegal instruction */
    Break_EXCn               =   3,              /*!<  Beakpoint */
    LdAddrUnalign_EXCn       =   4,              /*!<  Load address misaligned */
    LdFault_EXCn             =   5,              /*!<  Load access fault */
    StAddrUnalign_EXCn       =   6,              /*!<  Store or AMO address misaligned */
    StAccessFault_EXCn       =   7,              /*!<  Store or AMO access fault */
    UmodeEcall_EXCn          =   8,              /*!<  Environment call from User mode */
    MmodeEcall_EXCn          =  11,              /*!<  Environment call from Machine mode */
    NMI_EXCn                 = 0xfff,            /*!<  NMI interrupt */
} EXCn_Type;

/* =========================================================================================================================== */
/* ================                           Processor and Core Peripheral Section                           ================ */
/* =========================================================================================================================== */

/* ToDo: set the defines according your Device */
/* ToDo: define the correct core revision */
#if __riscv_xlen == 32

#ifndef __NUCLEI_CORE_REV
#define __NUCLEI_N_REV            0x0104    /*!< Core Revision r1p4 */
#else
#define __NUCLEI_N_REV            __NUCLEI_CORE_REV
#endif

#elif __riscv_xlen == 64

#ifndef __NUCLEI_CORE_REV
#define __NUCLEI_NX_REV           0x0100    /*!< Core Revision r1p0 */
#else
#define __NUCLEI_NX_REV           __NUCLEI_CORE_REV
#endif

#endif /* __riscv_xlen == 64 */

/* ToDo: define the correct core features for the  */
#define __ECLIC_PRESENT           1                     /*!< Set to 1 if ECLIC is present */
#define __ECLIC_BASEADDR          0xD2000000UL          /*!< Set to ECLIC baseaddr of your device */

//#define __ECLIC_INTCTLBITS        3                     /*!< Set to 1 - 8, the number of hardware bits are actually implemented in the clicintctl registers. */
#define __ECLIC_INTNUM            51                    /*!< Set to 1 - 1024, total interrupt number of ECLIC Unit */
#define __SYSTIMER_PRESENT        1                     /*!< Set to 1 if System Timer is present */
#define __SYSTIMER_BASEADDR       0xD1000000UL          /*!< Set to SysTimer baseaddr of your device */

/*!< Set to 0, 1, or 2, 0 not present, 1 single floating point unit present, 2 double floating point unit present */
#if !defined(__riscv_flen)
#define __FPU_PRESENT             0
#elif __riscv_flen == 32
#define __FPU_PRESENT             1
#else
#define __FPU_PRESENT             2
#endif

#define __DSP_PRESENT             1                     /*!< Set to 1 if DSP is present */
#define __PMP_PRESENT             1                     /*!< Set to 1 if PMP is present */
#define __PMP_ENTRY_NUM           16                    /*!< Set to 8 or 16, the number of PMP entries */
#define __ICACHE_PRESENT          1                     /*!< Set to 1 if I-Cache is present */
#define __DCACHE_PRESENT          1                     /*!< Set to 1 if D-Cache is present */
#define __Vendor_SysTickConfig    0                     /*!< Set to 1 if different SysTick Config is used */
#define __Vendor_EXCEPTION        0                     /*!< Set to 1 if vendor exception hander is present */

/** @} */ /* End of group Configuration_of_CMSIS */


#include <nmsis_core.h>                         /*!< Nuclei N/NX class processor and core peripherals */
/* ToDo: include your system_hbird.h file
         replace 'Device' with your device name */
#include "system_nuclei.h"                    /*!< hbird System */


/* ========================================  Start of section using anonymous unions  ======================================== */
#if   defined (__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

#define RTC_FREQ /*32768*/ 25000000		// Timer clk from RTL project

// The TIMER frequency is just the RTC frequency
#define SOC_TIMER_FREQ RTC_FREQ
/* =========================================================================================================================== */
/* ================                            Device Specific Peripheral Section                             ================ */
/* =========================================================================================================================== */


/** @addtogroup Device_Peripheral_peripherals
  * @{
  */

/****************************************************************************
 * Platform definitions
 *****************************************************************************/
// IOF Mappings


// Interrupt Handler Definitions
#define SOC_MTIMER_HANDLER          eclic_mtip_handler
#define SOC_SOFTINT_HANDLER         eclic_msip_handler

#define GPIO_BIT_ALL_ZERO           (0x0)
#define GPIO_BIT_ALL_ONE            (0xFFFFFFFF)



/* enum definitions */
typedef enum {
    DISABLE = 0,
    ENABLE = !DISABLE
} EventStatus, ControlStatus;

typedef enum {
    FALSE = 0,
    TRUE = !FALSE
} BOOL;

typedef enum {
    RESET = 0,
    SET = 1,
    MAX = 0X7FFFFFFF
} FlagStatus;

typedef enum {
    ERROR = 0,
    SUCCESS = !ERROR
} ErrStatus;

/**
  * @brief GPIO
  */
typedef struct {  /*!< GPIO Structure */
    __IOM uint32_t INPUT_VAL;
    __IOM uint32_t INPUT_EN;
    __IOM uint32_t OUTPUT_EN;
    __IOM uint32_t OUTPUT_VAL;
    __IOM uint32_t PULLUP_EN;
    __IOM uint32_t DRIVE;
    __IOM uint32_t PDE;
    __IOM uint32_t OD;
    __IOM uint32_t PUP;
    __IOM uint32_t RISE_IE;
    __IOM uint32_t RISE_IP;
    __IOM uint32_t FALL_IE;
    __IOM uint32_t FALL_IP;
    __IOM uint32_t HIGH_IE;
    __IOM uint32_t HIGH_IP;
    __IOM uint32_t LOW_IE;
    __IOM uint32_t LOW_IP;
    __IOM uint32_t IOF_EN;
    __IOM uint32_t IOF_SEL0;
    __IOM uint32_t IOF_SEL1;
    __IOM uint32_t EVENT_RISE_EN;
    __IOM uint32_t EVENT_FALL_EN;
    __IOM uint32_t OUTPUT_XOR;
    __IOM uint32_t RESERVED0[42];
    __IOM uint32_t INPUT_VAL_E;
    __IOM uint32_t INPUT_EN_E;
    __IOM uint32_t OUTPUT_EN_E;
    __IOM uint32_t OUTPUT_VAL_E;
    __IOM uint32_t PULLUP_EN_E;
    __IOM uint32_t DRIVE_E;
    __IOM uint32_t PDE_E;
    __IOM uint32_t OD_E;
    __IOM uint32_t PUP_E;
    __IOM uint32_t RISE_IE_E;
    __IOM uint32_t RISE_IP_E;
    __IOM uint32_t FALL_IE_E;
    __IOM uint32_t FALL_IP_E;
    __IOM uint32_t HIGH_IE_E;
    __IOM uint32_t HIGH_IP_E;
    __IOM uint32_t LOW_IE_E;
    __IOM uint32_t LOW_IP_E;
    __IOM uint32_t IOF_EN_E;
    __IOM uint32_t IOF_SEL0_E;
    __IOM uint32_t IOF_SEL1_E;
    __IOM uint32_t EVENT_RISE_EN_E;
    __IOM uint32_t EVENT_FALL_EN_E;
    __IOM uint32_t OUTPUT_XOR_E;

} GPIO_TypeDef;



/**
  * @brief I2C
  */
typedef struct {
   __IOM uint8_t PRERlo;
   __IOM uint8_t PRERhi;
  __IOM uint8_t CTR;
  __IOM uint8_t TXR_RXR;
  __IOM uint8_t CR_SR;
  __IOM uint8_t trise;
  __IOM uint8_t fltr;

} I2C_TypeDef;




/**
  * @brief UART (UART)
  */
typedef struct {
    __IOM uint32_t TXFIFO;
    __IOM uint32_t RXFIFO;
    __IOM uint32_t TXCTRL;
    __IOM uint32_t RXCTRL;
    __IOM uint32_t IE;
    __IOM uint32_t IP;
    __IOM uint32_t DIV;
    __IOM uint32_t STATUS;
    __IOM uint32_t SETUP;
    __IOM uint32_t ERROR;
    __IOM uint32_t IRQ_EN;
} UART_TypeDef;



typedef struct {
    __IOM uint32_t SCKDIV;
    __IOM uint32_t SCKMODE;
    __IOM uint32_t RESERVED0[2];
    __IOM uint32_t CSID;
    __IOM uint32_t CSDEF;
    __IOM uint32_t CSMODE;
    __IOM uint32_t RESERVED1[3];
    __IOM uint32_t DELAY0;
    __IOM uint32_t DELAY1;
    __IOM uint32_t RESERVED2[4];
    __IOM uint32_t FMT;
    __IOM uint32_t RESERVED3;
    __IOM uint32_t TXDATA;
    __IOM uint32_t RXDATA;
    __IOM uint32_t TXMARK;
    __IOM uint32_t RXMARK;
    __IOM uint32_t RESERVED4[2];
    __IOM uint32_t FCTRL;
    __IOM uint32_t FFMT;
    __IOM uint32_t RESERVED5[2];
    __IOM uint32_t IE;
    __IOM uint32_t IP;
    __IOM uint32_t STATUS;
    __IOM uint32_t RXEDGE;

} QSPI_TypeDef;

typedef struct{

  __IOM uint32_t SYSRESET;
  __IM uint32_t NMI;
  __IM uint32_t RESERVED0;
  __IOM  uint32_t CATCHE_CTL;
  __IOM uint32_t CLOCK_CTL;
}MISC_CTL_TypeDef;



/*@}*/ /* end of group hbird_Peripherals */


/* =========================================  End of section using anonymous unions  ========================================= */
#if defined (__GNUC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif


/* =========================================================================================================================== */
/* ================                          Device Specific Peripheral Address Map                           ================ */
/* =========================================================================================================================== */


/* ToDo: add here your device peripherals base addresses
         following is an example for timer */
/** @addtogroup Device_Peripheral_peripheralAddr
  * @{
  */
/* Peripheral and SRAM base address */
#define QSPI_FLASH_BASE                       (0x00000000UL)      /*!< (FLASH     ) Base Address */
#define ONCHIP_ROM_BASE                       (0x10000000UL)      /*!< (ROM       ) Base Address */
#define ONCHIP_ILM_BASE                       (0x08000000UL)      /*!< (ILM       ) Base Address */
#define ONCHIP_DLM_BASE                       (0x90000000UL)      /*!< (DLM       ) Base Address */
#define DEBUG_BASE                            (0xD3000000UL)      /*!< (DLM       ) Base Address */
#define NUCLEI_PERIPH_BASE                    (0xE0000000UL)      /*!< (Peripheral) Base Address */
#define SYSTEM_BUS                            (0x40000000UL)      /*!< (Peripheral) Base Address */

/* Peripheral memory map */ 

/*!< (MISC_Ctrl) Base Address */
#define MISC_CTL_BASE         (NUCLEI_PERIPH_BASE + 0x00000) 

#define UART0_BASE            (NUCLEI_PERIPH_BASE + 0x10000)          /*!< (UART0) Base Address */
#define GPIO_BASE             (NUCLEI_PERIPH_BASE + 0x20000)          /*!< (GPIO) Base Address */
#define I2C_BASE              (NUCLEI_PERIPH_BASE + 0x40000)          /*!< (I2C_BASE) Base Address */
#define QSPI_BASE             (NUCLEI_PERIPH_BASE + 0x50000)          /*!< (QSPI0) Base Address */
#define QSPI0_BASE            (NUCLEI_PERIPH_BASE + 0x60000)          /*!< (UART2) Base Address */




/** @} */ /* End of group Device_Peripheral_peripheralAddr */


/* =========================================================================================================================== */
/* ================                                  Peripheral declaration                                   ================ */
/* =========================================================================================================================== */


/* ToDo: add here your device peripherals pointer definitions
         following is an example for timer */
/** @addtogroup Device_Peripheral_declaration
  * @{
  */
#define GPIO        ((GPIO_TypeDef *) GPIO_BASE)
#define UART0       ((UART_TypeDef *) UART0_BASE)
//#define QSPI0       ((QSPI_TypeDef *) QSPI0_BASE)
//#define QSPI        ((QSPI_TypeDef *) QSPI_BASE)

#define MISC_CTL    ((MISC_CTL_TypeDef *) MISC_CTL_BASE)

#define I2C         ((I2C_TypeDef *)I2C_BASE) 


// Helper functions
#define _REG8(p, i)             (*(volatile uint8_t *) ((p) + (i)))
#define _REG32(p, i)            (*(volatile uint32_t *) ((p) + (i)))
#define _REG32P(p, i)           ((volatile uint32_t *) ((p) + (i)))


/* ToDo: add here your device peripherals pointer definitions
         following is an example for timer */
/** @addtogroup Device_Peripheral_declaration
  * @{
  */
/* bit operations */
#define REG32(addr)                  (*(volatile uint32_t *)(uint32_t)(addr))
#define REG16(addr)                  (*(volatile uint16_t *)(uint32_t)(addr))
#define REG8(addr)                   (*(volatile uint8_t *)(uint32_t)(addr))
#define BIT(x)                       ((uint32_t)((uint32_t)0x01U<<(x)))
#define BITS(start, end)             ((0xFFFFFFFFUL << (start)) & (0xFFFFFFFFUL >> (31U - (uint32_t)(end)))) 
#define GET_BITS(regval, start, end) (((regval) & BITS((start),(end))) >> (start))
#define GET_BIT(regval, x) (((regval) & BIT(x) >> (x)))



#define GPIO_REG(offset)          _REG32(GPIO_BASE, offset)
#define TIMER0_REG(offset)        _REG32(TIMER0_BASE, offset)

#define QSPI0_REG(offset)          _REG32(QSPI0_BASE, offset)
#define QSPI_REG(offset)          _REG32(QSPI_BASE, offset)

#define UART0_REG(offset)         _REG32(UART0_BASE, offset)
#define UART1_REG(offset)         _REG32(UART1_BASE, offset)


// Misc


uint32_t get_cpu_freq();
void delay_1ms(uint32_t count);
void pass_fail_simulation(uint32_t state);

/** @} */ /* End of group hbird */

/** @} */ /* End of group Nuclei */

#ifdef __cplusplus
}
#endif

#endif  /* __NUCLEI_H__ */

