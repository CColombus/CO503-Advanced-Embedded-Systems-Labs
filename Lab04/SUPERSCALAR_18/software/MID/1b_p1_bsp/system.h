/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'CPU_1b_p1_sub_cpu_0' in SOPC Builder design 'FTOP_MSOC'
 * SOPC Builder design path: ../../../FTOP_MSOC.sopcinfo
 *
 * Generated: Sat Jun 22 20:13:11 IST 2024
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00010820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 75000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1d
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00008020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 75000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x11
#define ALT_CPU_NAME "CPU_1b_p1_sub_cpu_0"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00008000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00010820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 75000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1d
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00008020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x11
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00008000


/*
 * CPU_1b_p1_oc_ram_0 configuration
 *
 */

#define ALT_MODULE_CLASS_CPU_1b_p1_oc_ram_0 altera_avalon_onchip_memory2
#define CPU_1B_P1_OC_RAM_0_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define CPU_1B_P1_OC_RAM_0_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define CPU_1B_P1_OC_RAM_0_BASE 0x8000
#define CPU_1B_P1_OC_RAM_0_CONTENTS_INFO ""
#define CPU_1B_P1_OC_RAM_0_DUAL_PORT 0
#define CPU_1B_P1_OC_RAM_0_GUI_RAM_BLOCK_TYPE "AUTO"
#define CPU_1B_P1_OC_RAM_0_INIT_CONTENTS_FILE "FTOP_MSOC_CPU_1b_p1_oc_ram_0"
#define CPU_1B_P1_OC_RAM_0_INIT_MEM_CONTENT 1
#define CPU_1B_P1_OC_RAM_0_INSTANCE_ID "NONE"
#define CPU_1B_P1_OC_RAM_0_IRQ -1
#define CPU_1B_P1_OC_RAM_0_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CPU_1B_P1_OC_RAM_0_NAME "/dev/CPU_1b_p1_oc_ram_0"
#define CPU_1B_P1_OC_RAM_0_NON_DEFAULT_INIT_FILE_ENABLED 0
#define CPU_1B_P1_OC_RAM_0_RAM_BLOCK_TYPE "AUTO"
#define CPU_1B_P1_OC_RAM_0_READ_DURING_WRITE_MODE "DONT_CARE"
#define CPU_1B_P1_OC_RAM_0_SINGLE_CLOCK_OP 0
#define CPU_1B_P1_OC_RAM_0_SIZE_MULTIPLE 1
#define CPU_1B_P1_OC_RAM_0_SIZE_VALUE 20480
#define CPU_1B_P1_OC_RAM_0_SPAN 20480
#define CPU_1B_P1_OC_RAM_0_TYPE "altera_avalon_onchip_memory2"
#define CPU_1B_P1_OC_RAM_0_WRITABLE 1


/*
 * CPU_1b_p1_timer_0 configuration
 *
 */

#define ALT_MODULE_CLASS_CPU_1b_p1_timer_0 altera_avalon_timer
#define CPU_1B_P1_TIMER_0_ALWAYS_RUN 0
#define CPU_1B_P1_TIMER_0_BASE 0x11000
#define CPU_1B_P1_TIMER_0_COUNTER_SIZE 32
#define CPU_1B_P1_TIMER_0_FIXED_PERIOD 0
#define CPU_1B_P1_TIMER_0_FREQ 75000000
#define CPU_1B_P1_TIMER_0_IRQ 1
#define CPU_1B_P1_TIMER_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define CPU_1B_P1_TIMER_0_LOAD_VALUE 74999
#define CPU_1B_P1_TIMER_0_MULT 0.001
#define CPU_1B_P1_TIMER_0_NAME "/dev/CPU_1b_p1_timer_0"
#define CPU_1B_P1_TIMER_0_PERIOD 1
#define CPU_1B_P1_TIMER_0_PERIOD_UNITS "ms"
#define CPU_1B_P1_TIMER_0_RESET_OUTPUT 0
#define CPU_1B_P1_TIMER_0_SNAPSHOT 1
#define CPU_1B_P1_TIMER_0_SPAN 32
#define CPU_1B_P1_TIMER_0_TICKS_PER_SEC 1000
#define CPU_1B_P1_TIMER_0_TIMEOUT_PULSE_OUTPUT 0
#define CPU_1B_P1_TIMER_0_TYPE "altera_avalon_timer"


/*
 * CPU_1b_p1_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_CPU_1b_p1_uart_0 altera_avalon_jtag_uart
#define CPU_1B_P1_UART_0_BASE 0x11020
#define CPU_1B_P1_UART_0_IRQ 16
#define CPU_1B_P1_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define CPU_1B_P1_UART_0_NAME "/dev/CPU_1b_p1_uart_0"
#define CPU_1B_P1_UART_0_READ_DEPTH 64
#define CPU_1B_P1_UART_0_READ_THRESHOLD 8
#define CPU_1B_P1_UART_0_SPAN 8
#define CPU_1B_P1_UART_0_TYPE "altera_avalon_jtag_uart"
#define CPU_1B_P1_UART_0_WRITE_DEPTH 64
#define CPU_1B_P1_UART_0_WRITE_THRESHOLD 8


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_FIFO
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_GEN2


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/CPU_1b_p1_uart_0"
#define ALT_STDERR_BASE 0x11020
#define ALT_STDERR_DEV CPU_1b_p1_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/CPU_1b_p1_uart_0"
#define ALT_STDIN_BASE 0x11020
#define ALT_STDIN_DEV CPU_1b_p1_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/CPU_1b_p1_uart_0"
#define ALT_STDOUT_BASE 0x11020
#define ALT_STDOUT_DEV CPU_1b_p1_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "FTOP_MSOC"


/*
 * fifo_qa_p1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_qa_p1_in_csr altera_avalon_fifo
#define FIFO_QA_P1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_QA_P1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_QA_P1_IN_CSR_BASE 0x10000020
#define FIFO_QA_P1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_QA_P1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_QA_P1_IN_CSR_ERROR_WIDTH 8
#define FIFO_QA_P1_IN_CSR_FIFO_DEPTH 128
#define FIFO_QA_P1_IN_CSR_IRQ -1
#define FIFO_QA_P1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_QA_P1_IN_CSR_NAME "/dev/fifo_qa_p1_in_csr"
#define FIFO_QA_P1_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_QA_P1_IN_CSR_SPAN 32
#define FIFO_QA_P1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_QA_P1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_QA_P1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_QA_P1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_QA_P1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_QA_P1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_QA_P1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_QA_P1_IN_CSR_USE_IRQ 0
#define FIFO_QA_P1_IN_CSR_USE_PACKET 1
#define FIFO_QA_P1_IN_CSR_USE_READ_CONTROL 0
#define FIFO_QA_P1_IN_CSR_USE_REGISTER 0
#define FIFO_QA_P1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_qa_p1_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_qa_p1_out altera_avalon_fifo
#define FIFO_QA_P1_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_QA_P1_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_QA_P1_OUT_BASE 0x10000040
#define FIFO_QA_P1_OUT_BITS_PER_SYMBOL 16
#define FIFO_QA_P1_OUT_CHANNEL_WIDTH 8
#define FIFO_QA_P1_OUT_ERROR_WIDTH 8
#define FIFO_QA_P1_OUT_FIFO_DEPTH 128
#define FIFO_QA_P1_OUT_IRQ -1
#define FIFO_QA_P1_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_QA_P1_OUT_NAME "/dev/fifo_qa_p1_out"
#define FIFO_QA_P1_OUT_SINGLE_CLOCK_MODE 1
#define FIFO_QA_P1_OUT_SPAN 4
#define FIFO_QA_P1_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_QA_P1_OUT_TYPE "altera_avalon_fifo"
#define FIFO_QA_P1_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_QA_P1_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_QA_P1_OUT_USE_AVALONST_SINK 0
#define FIFO_QA_P1_OUT_USE_AVALONST_SOURCE 0
#define FIFO_QA_P1_OUT_USE_BACKPRESSURE 1
#define FIFO_QA_P1_OUT_USE_IRQ 0
#define FIFO_QA_P1_OUT_USE_PACKET 1
#define FIFO_QA_P1_OUT_USE_READ_CONTROL 0
#define FIFO_QA_P1_OUT_USE_REGISTER 0
#define FIFO_QA_P1_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_qb_p1_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_qb_p1_in altera_avalon_fifo
#define FIFO_QB_P1_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_QB_P1_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_QB_P1_IN_BASE 0x10000044
#define FIFO_QB_P1_IN_BITS_PER_SYMBOL 16
#define FIFO_QB_P1_IN_CHANNEL_WIDTH 8
#define FIFO_QB_P1_IN_ERROR_WIDTH 8
#define FIFO_QB_P1_IN_FIFO_DEPTH 32
#define FIFO_QB_P1_IN_IRQ -1
#define FIFO_QB_P1_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_QB_P1_IN_NAME "/dev/fifo_qb_p1_in"
#define FIFO_QB_P1_IN_SINGLE_CLOCK_MODE 1
#define FIFO_QB_P1_IN_SPAN 4
#define FIFO_QB_P1_IN_SYMBOLS_PER_BEAT 2
#define FIFO_QB_P1_IN_TYPE "altera_avalon_fifo"
#define FIFO_QB_P1_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_QB_P1_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_QB_P1_IN_USE_AVALONST_SINK 0
#define FIFO_QB_P1_IN_USE_AVALONST_SOURCE 0
#define FIFO_QB_P1_IN_USE_BACKPRESSURE 1
#define FIFO_QB_P1_IN_USE_IRQ 0
#define FIFO_QB_P1_IN_USE_PACKET 1
#define FIFO_QB_P1_IN_USE_READ_CONTROL 0
#define FIFO_QB_P1_IN_USE_REGISTER 0
#define FIFO_QB_P1_IN_USE_WRITE_CONTROL 1


/*
 * fifo_qb_p1_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_qb_p1_in_csr altera_avalon_fifo
#define FIFO_QB_P1_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_QB_P1_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_QB_P1_IN_CSR_BASE 0x10000000
#define FIFO_QB_P1_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_QB_P1_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_QB_P1_IN_CSR_ERROR_WIDTH 8
#define FIFO_QB_P1_IN_CSR_FIFO_DEPTH 32
#define FIFO_QB_P1_IN_CSR_IRQ -1
#define FIFO_QB_P1_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_QB_P1_IN_CSR_NAME "/dev/fifo_qb_p1_in_csr"
#define FIFO_QB_P1_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_QB_P1_IN_CSR_SPAN 32
#define FIFO_QB_P1_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_QB_P1_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_QB_P1_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_QB_P1_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_QB_P1_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_QB_P1_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_QB_P1_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_QB_P1_IN_CSR_USE_IRQ 0
#define FIFO_QB_P1_IN_CSR_USE_PACKET 1
#define FIFO_QB_P1_IN_CSR_USE_READ_CONTROL 0
#define FIFO_QB_P1_IN_CSR_USE_REGISTER 0
#define FIFO_QB_P1_IN_CSR_USE_WRITE_CONTROL 1


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK CPU_1B_P1_TIMER_0
#define ALT_TIMESTAMP_CLK CPU_1B_P1_TIMER_0


/*
 * mem_info configuration
 *
 */

#define ALT_MODULE_CLASS_mem_info altera_avalon_onchip_memory2
#define MEM_INFO_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define MEM_INFO_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define MEM_INFO_BASE 0x10010000
#define MEM_INFO_CONTENTS_INFO ""
#define MEM_INFO_DUAL_PORT 0
#define MEM_INFO_GUI_RAM_BLOCK_TYPE "AUTO"
#define MEM_INFO_INIT_CONTENTS_FILE "FTOP_MSOC_mem_info"
#define MEM_INFO_INIT_MEM_CONTENT 1
#define MEM_INFO_INSTANCE_ID "NONE"
#define MEM_INFO_IRQ -1
#define MEM_INFO_IRQ_INTERRUPT_CONTROLLER_ID -1
#define MEM_INFO_NAME "/dev/mem_info"
#define MEM_INFO_NON_DEFAULT_INIT_FILE_ENABLED 0
#define MEM_INFO_RAM_BLOCK_TYPE "AUTO"
#define MEM_INFO_READ_DURING_WRITE_MODE "DONT_CARE"
#define MEM_INFO_SINGLE_CLOCK_OP 0
#define MEM_INFO_SIZE_MULTIPLE 1
#define MEM_INFO_SIZE_VALUE 1024
#define MEM_INFO_SPAN 1024
#define MEM_INFO_TYPE "altera_avalon_onchip_memory2"
#define MEM_INFO_WRITABLE 1

#endif /* __SYSTEM_H_ */
