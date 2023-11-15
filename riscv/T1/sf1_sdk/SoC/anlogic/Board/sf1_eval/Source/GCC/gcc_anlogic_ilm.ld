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
 * @file     gcc_hbird_ilm.ld
 * @brief    GNU Linker Script for Nuclei N/NX based device in ilm Download Mode
 * @version  V1.0.0
 * @date     17. Dec 2019
 ******************************************************************************/
OUTPUT_ARCH( "riscv" )
/*Hunter@: set "_start" as the Entry Address*/
ENTRY( _start )

/*Hunter@:
	MEMORY
	{
		name [(attr)] : ORIGIN = origin, LENGTH = len
		...
	}
	name: 
	attr: attribute, 
		â€˜Râ€?  Read-only section; â€˜Wâ€? Read/write section;â€˜Xâ€?  Executable section;
		â€˜Aâ€? Allocatable section; â€˜Iâ€? Initialized section; â€˜Lâ€? Same as â€˜Iâ€?;
		â€?!â€? Invert the sense of any of the preceding attributes.
	ORIGIN: start address;
	LENGTH: memory size;
*/
MEMORY
{
  ilm (rxai!w)    : ORIGIN = 0x80000000, LENGTH = 64K
  ram (wxa!ri)    : ORIGIN = 0x80010000, LENGTH = 16K
  sysmem (rxaiw)  : ORIGIN = 0xa0000000, LENGTH = 64K
  dlm (rxai!w)    : ORIGIN = 0x08000000, LENGTH = 8K
}

/*Hunter@: The SECTIONS command tells the linker how to map input segments to output segments,
			and how to place output segments in memory.
*/
SECTIONS
{
  __stack_size = DEFINED(__stack_size) ? __stack_size : 2K;

  .init           :
  {
    *(.vtable)
    KEEP (*(SORT_NONE(.init)))
  } >ilm AT>ilm 

 .spilalign         :
  {
    . = ALIGN(4);
    PROVIDE( _spi_lma = . );
  } >ilm AT>ilm 

  .spialign         :
  {
    PROVIDE( _spi = . );
  } >dlm AT>ilm 

  .spi_flash           :
  {
    KEEP (*(SORT_NONE(.spi_flash)))
  } >dlm AT>ilm 

 .espialign           :
  {
    PROVIDE( _espi = . );    
  } >dlm AT>ilm 

  PROVIDE( _espi = . );
  
  .ilalign         :
  {
    . = ALIGN(4);
    PROVIDE( _ilm_lma = . );
  } >ilm AT>ilm 

  .mem_data1           :
  {
    *(.mem_data)
  } >sysmem AT>sysmem 

  .ialign         :
  {
    PROVIDE( _ilm = . );
  } >ilm AT>ilm 

  .text           :
  {
    *(.text.unlikely .text.unlikely.*)
    *(.text.startup .text.startup.*)
    *(.text .text.*)
    *(.gnu.linkonce.t.*)
  } >ilm AT>ilm

  .rodata : ALIGN(4)
  {
    . = ALIGN(4);
    *(.rdata)
    *(.rodata .rodata.*)
    *(.gnu.linkonce.r.*)
    . = ALIGN(8);
    *(.srodata.cst16)
    *(.srodata.cst8)
    *(.srodata.cst4)
    *(.srodata.cst2)
    *(.srodata .srodata.*)
  } >ilm AT>ilm 

  .fini           :
  {
    KEEP (*(SORT_NONE(.fini)))
  } >ilm AT>ilm 

  . = ALIGN(4);

  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);
  PROVIDE( _eilm = . );


  .preinit_array  :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } >ilm AT>ilm 

  .init_array     :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT_BY_INIT_PRIORITY(.init_array.*) SORT_BY_INIT_PRIORITY(.ctors.*)))
    KEEP (*(.init_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .ctors))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >ilm AT>ilm 

  .fini_array     :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(SORT_BY_INIT_PRIORITY(.fini_array.*) SORT_BY_INIT_PRIORITY(.dtors.*)))
    KEEP (*(.fini_array EXCLUDE_FILE (*crtbegin.o *crtbegin?.o *crtend.o *crtend?.o ) .dtors))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >ilm AT>ilm 

  .ctors          :
  {
    /* gcc uses crtbegin.o to find the start of
       the constructors, so we make sure it is
       first.  Because this is a wildcard, it
       doesn't matter if the user does not
       actually link against crtbegin.o; the
       linker won't look for a file to match a
       wildcard.  The wildcard also means that it
       doesn't matter which directory crtbegin.o
       is in.  */
    KEEP (*crtbegin.o(.ctors))
    KEEP (*crtbegin?.o(.ctors))
    /* We don't want to include the .ctor section from
       the crtend.o file until after the sorted ctors.
       The .ctor section from the crtend file contains the
       end of ctors marker and it must be last */
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .ctors))
    KEEP (*(SORT(.ctors.*)))
    KEEP (*(.ctors))
  } >ilm AT>ilm 

  .dtors          :
  {
    KEEP (*crtbegin.o(.dtors))
    KEEP (*crtbegin?.o(.dtors))
    KEEP (*(EXCLUDE_FILE (*crtend.o *crtend?.o ) .dtors))
    KEEP (*(SORT(.dtors.*)))
    KEEP (*(.dtors))
  } >ilm AT>ilm 


  .lalign         :
  {
    . = ALIGN(4);
    PROVIDE( _data_lma = . );
  } >ilm AT>ilm 

  .dalign         :
  {
    . = ALIGN(4);
    PROVIDE( _data = . );
  } >ilm AT>ilm 

  .data          :
  {
    *(.data .data.*)
    *(.gnu.linkonce.d.*)
    . = ALIGN(8);
    PROVIDE( __global_pointer$ = . + 0x800 );
    *(.sdata .sdata.* .sdata*)
    *(.gnu.linkonce.s.*)
  } >ilm AT>ilm 

  . = ALIGN(4);
  PROVIDE( _edata = . );
  PROVIDE( edata = . );

  .noinit        :
  {
    PROVIDE (__no_init_start = .);
    PROVIDE (__no_init_end = .);
  }>ilm AT>ilm

  PROVIDE( _fbss = . );
  PROVIDE( __bss_start = . );
  .bss            :
  {
    *(.sbss*)
    *(.gnu.linkonce.sb.*)
    *(.bss .bss.*)
    *(.gnu.linkonce.b.*)
    *(COMMON)
    . = ALIGN(4);
  } >ram AT>ram 

  . = ALIGN(8);
  PROVIDE( _end = . );
  PROVIDE( end = . );

  .stack ORIGIN(ram) + LENGTH(ram) - __stack_size :
  {
    PROVIDE( _heap_end = . );
    . = __stack_size;
    PROVIDE( _sp = . );
  } >ram AT>ram 
}
