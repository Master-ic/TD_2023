/*
 * Copyright (c) 2019 Nuclei Limited. All rights reserved.
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
/******************************************************************************
 * \file     startup_hbird.S
 * \brief    NMSIS Nuclei N/NX Class Core based Core Device Startup File for
 *  Nuclei   HummingBird evaluation SoC which support Nuclei N/NX class cores
 * \version  V1.00
 * \date     17. Dec 2019
 *
 ******************************************************************************/

#include "riscv_encoding.h"

.macro DECLARE_INT_HANDLER  INT_HDL_NAME
#if defined(__riscv_xlen) && (__riscv_xlen == 32)
    .word \INT_HDL_NAME
#else
    .dword \INT_HDL_NAME
#endif
.endm

/*
 * === Different Download and Running Mode ===
 * flashxip: Program will to be download into flash and run directly in Flash
 * flash: Program will be download into flash, when running, program will be copied to ilm/ram and run in ilm/ram
 * ilm: Program will be download into ilm/ram and run directly in ilm/ram, program lost when poweroff
 */

/*** Vector Table Code Section ***/
    /*
     * Put the interrupt vectors in this section according to the run mode:
     * FlashXIP: .vtable
     * ILM: .vtable
     * Flash: .vtable_ilm
     */
#if defined(DOWNLOAD_MODE) && (DOWNLOAD_MODE == DOWNLOAD_MODE_FLASH)
    .section .vtable_ilm
#else
    .section .vtable
#endif

    .weak  eclic_msip_handler
    .weak  eclic_mtip_handler
    .weak  uart0_handler
    .weak  i2c_handler
    .weak  QSPI0_handler
    .weak  QSPI_handler
    .weak  gpio0_handler
    .weak  gpio1_handler
    .weak  gpio2_handler
    .weak  gpio3_handler
    .weak  gpio4_handler
    .weak  gpio5_handler
    .weak  gpio6_handler
    .weak  gpio7_handler
    .weak  fpga0_handler
    .weak  fpga1_handler
    .weak  fpga2_handler
    .weak  fpga3_handler
    .weak  fpga4_handler
    .weak  fpga5_handler
    .weak  fpga6_handler
    .weak  fpga7_handler
    .weak  fpga8_handler
    .weak  fpga9_handler
    .weak  fpga10_handler
    .weak  fpga11_handler
    .weak  fpga12_handler
    .weak  fpga13_handler
    .weak  fpga14_handler
    .weak  fpga15_handler

    .globl vector_base
vector_base:
#if defined(DOWNLOAD_MODE) && (DOWNLOAD_MODE != DOWNLOAD_MODE_FLASH)
  //  j _start                                                /* 0: Reserved, Jump to _start when reset for ILM/FlashXIP mode.*/
    la ra,_start    // fix according to suggestion of S.W
    ret 
    .align LOG_REGBYTES                                     /*    Need to align 4 byte for RV32, 8 Byte for RV64 */
#else
    DECLARE_INT_HANDLER     default_intexc_handler          /* 0: Reserved, default handler for Flash download mode */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 1: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 2: Reserved */
#endif
   // DECLARE_INT_HANDLER     default_intexc_handler          /* 1: Reserved */
   // DECLARE_INT_HANDLER     default_intexc_handler          /* 2: Reserved */
    DECLARE_INT_HANDLER     eclic_msip_handler              /* 3: Machine software interrupt */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 4: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 5: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 6: Reserved */
    DECLARE_INT_HANDLER     eclic_mtip_handler              /* 7: Machine timer interrupt */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 8: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 9: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 10: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 11: Reserved */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 12: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 13: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 14: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 15: Reserved */

    DECLARE_INT_HANDLER     default_intexc_handler          /* 16: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 17: Reserved */
    DECLARE_INT_HANDLER     default_intexc_handler          /* 18: Reserved */
    DECLARE_INT_HANDLER     uart0_handler                   /* 19: Interrupt 19 */

    DECLARE_INT_HANDLER     i2c_handler                     /* 21: Interrupt 21 */
    DECLARE_INT_HANDLER     QSPI0_handler                   /* 22: Interrupt 22 */
    DECLARE_INT_HANDLER     QSPI_handler                    /* 29: Interrupt 29 */
    DECLARE_INT_HANDLER     gpio0_handler                   /* 30: Interrupt 30 */

    DECLARE_INT_HANDLER     gpio1_handler                   /* 31: Interrupt 31 */
    DECLARE_INT_HANDLER     gpio2_handler                   /* 32: Interrupt 32 */
    DECLARE_INT_HANDLER     gpio3_handler                   /* 33: Interrupt 33 */
    DECLARE_INT_HANDLER     gpio4_handler                   /* 34: Interrupt 34 */

    DECLARE_INT_HANDLER     gpio5_handler                   /* 35: Interrupt 35 */
    DECLARE_INT_HANDLER     gpio6_handler                   /* 36: Interrupt 36 */
    DECLARE_INT_HANDLER     gpio7_handler                   /* 37: Interrupt 37 */
    DECLARE_INT_HANDLER     fpga0_handler                   /* 38: Interrupt 38 */

    DECLARE_INT_HANDLER     fpga1_handler                   /* 39: Interrupt 39 */
    DECLARE_INT_HANDLER     fpga2_handler                    /*40: Interrupt 40 */
    DECLARE_INT_HANDLER     fpga3_handler                   /* 41: Interrupt 41 */
    DECLARE_INT_HANDLER     fpga4_handler                   /* 42: Interrupt 42 */

    DECLARE_INT_HANDLER     fpga5_handler                   /* 43: Interrupt 43 */
    DECLARE_INT_HANDLER     fpga6_handler                   /* 44: Interrupt 44 */
    DECLARE_INT_HANDLER     fpga7_handler                   /* 45: Interrupt 45 */
    DECLARE_INT_HANDLER     fpga8_handler                   /* 43: Interrupt 43 */

    DECLARE_INT_HANDLER     fpga9_handler                   /* 44: Interrupt 44 */
    DECLARE_INT_HANDLER     fpga10_handler                   /* 45: Interrupt 45 */
    DECLARE_INT_HANDLER     fpga11_handler                   /* 44: Interrupt 44 */
    DECLARE_INT_HANDLER     fpga12_handler                   /* 45: Interrupt 45 */
    DECLARE_INT_HANDLER     fpga13_handler                   /* 44: Interrupt 44 */
    DECLARE_INT_HANDLER     fpga14_handler                   /* 45: Interrupt 45 */
    DECLARE_INT_HANDLER     fpga15_handler                   /* 45: Interrupt 45 */

    .section .init


    .globl _start
    .type _start,@function
    .option norvc
/**
 * Reset Handler called on controller reset
 */
_start:

    /* ===== Startup Stage 1 ===== */
    /* Disable Global Interrupt */
   // li a0,1
    csrc CSR_MSTATUS, MSTATUS_MIE

  //rxedge  only for temp use  
   la a0, SPI0_RXEDGE_ADDR
   la a1, 0x1
   sw a1, 0(a0)


   /*speed up boot up */
   /* 0x82=b0000 1000 0010,
    * bit0=0: choose osc,otherwise choose gclk;
	* bit[5:1]=1: 1/(N+1)=1/2;
	*/
    la a0, CLK_REG_ADDR
    la a1, 0x83
    sw a1, 0(a0)
    
    /*F_spi=1/[2(div+1)], default div=0*/
    la a0, SPI0_REG_ADDR
    la a1, 0x0
    sw a1, 0(a0)


 //set 4-wire mode 
   la a0, SPI0_FFMT_ADDR
   la a1, 0x6B2087
   sw a1, 0(a0)
// enable busrt mode 
   la a0, SPI0_FCTRL_ADDR
   la a1, 0x09
   sw a1, 0(a0)

    /* Initialize GP and Stack Pointer SP */
    .option push
    .option norelax
    la gp, __global_pointer$
    .option pop
    la sp, _sp

   /*
     * Set the the NMI base mnvec to share
     * with mtvec by setting CSR_MMISC_CTL
     * bit 9 NMI_CAUSE_FFF to 1
     */
    li t0, MMISC_CTL_NMI_CAUSE_FFF
    csrs CSR_MMISC_CTL, t0

    /*
     * Intialize ECLIC vector interrupt
     * base address mtvt to vector_base
     */
    la t0, vector_base
    csrw CSR_MTVT, t0


    /*
     * Set ECLIC non-vector entry to be controlled
     * by mtvt2 CSR register.
     * Intialize ECLIC non-vector interrupt
     * base address mtvt2 to irq_entry.
     */
    la t0, irq_entry
    csrw CSR_MTVT2, t0
    csrs CSR_MTVT2, 0x1

    /*
     * Set Exception Entry MTVEC to exc_entry
     * Due to settings above, Exception and NMI
     * will share common entry.
     */
    la t0, exc_entry
    csrw CSR_MTVEC, t0

    /* Set the interrupt processing mode to ECLIC mode */
    la t0, 0x3f
    csrc CSR_MTVEC, t0
    csrs CSR_MTVEC, 0x3

    /* ===== Startup Stage 2 ===== */

#ifdef __riscv_flen
    /* Enable FPU */
    li t0, MSTATUS_FS
    csrs mstatus, t0
    csrw fcsr, x0
#endif

    /* Enable mcycle and minstret counter */
    csrci CSR_MCOUNTINHIBIT, 0x5

    /* ===== Startup Stage 3 ===== */
    /*
     * Load code section from FLASH to ILM
     * when code LMA is different with VMA
     */
    la a0, _ilm_lma
    la a1, _ilm
    /* If the ILM phy-address same as the logic-address, then quit */
    beq a0, a1, 2f
    la a2, _eilm
    bgeu a1, a2, 2f

1:
    /* Load code section if necessary */
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, 1b
2:
    /* Load data section */
    la a0, _data_lma
    la a1, _data
    la a2, _edata
    bgeu a1, a2, 2f
1:
    lw t0, (a0)
    sw t0, (a1)
    addi a0, a0, 4
    addi a1, a1, 4
    bltu a1, a2, 1b
2:
    /* Clear bss section */
    la a0, __bss_start
    la a1, _end
    bgeu a0, a1, 2f
1:
    sw zero, (a0)
    addi a0, a0, 4
    bltu a0, a1, 1b
2:

    /*
     * Call vendor defined SystemInit to
     * initialize the micro-controller system
     */
    call SystemInit

    /* Call global constructors */
    la a0, __libc_fini_array
    call atexit
    /* Call C/C++ constructor start up code */
    call __libc_init_array

    /* ===== Call Main Function  ===== */
    /* argc = argv = 0 */
    li a0, 0
    li a1, 0

#ifdef RTOS_RTTHREAD
    // Call entry function when using RT-Thread
    call entry
#else
    call main
#endif

1:
    j 1b
