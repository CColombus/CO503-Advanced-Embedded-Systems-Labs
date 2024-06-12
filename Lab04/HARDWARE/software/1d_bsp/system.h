/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu_1d' in SOPC Builder design 'Mega_JSoC'
 * SOPC Builder design path: D:/SEM6/CO503/Lab04/HARDWARE/Mega_JSoC.sopcinfo
 *
 * Generated: Wed Jun 12 18:15:04 IST 2024
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

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00020820
#define ALT_CPU_CPU_FREQ 75000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00010020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 75000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x12
#define ALT_CPU_NAME "cpu_1d"
#define ALT_CPU_RESET_ADDR 0x00010000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00020820
#define NIOS2_CPU_FREQ 75000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00010020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x12
#define NIOS2_RESET_ADDR 0x00010000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_FIFO
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS


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
#define ALT_STDERR "/dev/jtag_uart_1d"
#define ALT_STDERR_BASE 0x21068
#define ALT_STDERR_DEV jtag_uart_1d
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_1d"
#define ALT_STDIN_BASE 0x21068
#define ALT_STDIN_DEV jtag_uart_1d
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_1d"
#define ALT_STDOUT_BASE 0x21068
#define ALT_STDOUT_DEV jtag_uart_1d
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "Mega_JSoC"


/*
 * fifo_1c_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1c_in_csr altera_avalon_fifo
#define FIFO_1C_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1C_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1C_IN_CSR_BASE 0x21020
#define FIFO_1C_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1C_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1C_IN_CSR_ERROR_WIDTH 8
#define FIFO_1C_IN_CSR_FIFO_DEPTH 32
#define FIFO_1C_IN_CSR_IRQ -1
#define FIFO_1C_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1C_IN_CSR_NAME "/dev/fifo_1c_in_csr"
#define FIFO_1C_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_1C_IN_CSR_SPAN 32
#define FIFO_1C_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1C_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1C_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1C_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1C_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1C_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1C_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1C_IN_CSR_USE_IRQ 0
#define FIFO_1C_IN_CSR_USE_PACKET 1
#define FIFO_1C_IN_CSR_USE_READ_CONTROL 0
#define FIFO_1C_IN_CSR_USE_REGISTER 0
#define FIFO_1C_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_1c_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1c_out altera_avalon_fifo
#define FIFO_1C_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1C_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1C_OUT_BASE 0x21074
#define FIFO_1C_OUT_BITS_PER_SYMBOL 16
#define FIFO_1C_OUT_CHANNEL_WIDTH 8
#define FIFO_1C_OUT_ERROR_WIDTH 8
#define FIFO_1C_OUT_FIFO_DEPTH 32
#define FIFO_1C_OUT_IRQ -1
#define FIFO_1C_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1C_OUT_NAME "/dev/fifo_1c_out"
#define FIFO_1C_OUT_SINGLE_CLOCK_MODE 1
#define FIFO_1C_OUT_SPAN 4
#define FIFO_1C_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_1C_OUT_TYPE "altera_avalon_fifo"
#define FIFO_1C_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1C_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1C_OUT_USE_AVALONST_SINK 0
#define FIFO_1C_OUT_USE_AVALONST_SOURCE 0
#define FIFO_1C_OUT_USE_BACKPRESSURE 1
#define FIFO_1C_OUT_USE_IRQ 0
#define FIFO_1C_OUT_USE_PACKET 1
#define FIFO_1C_OUT_USE_READ_CONTROL 0
#define FIFO_1C_OUT_USE_REGISTER 0
#define FIFO_1C_OUT_USE_WRITE_CONTROL 1


/*
 * fifo_1d_in configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1d_in altera_avalon_fifo
#define FIFO_1D_IN_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1D_IN_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1D_IN_BASE 0x21078
#define FIFO_1D_IN_BITS_PER_SYMBOL 16
#define FIFO_1D_IN_CHANNEL_WIDTH 8
#define FIFO_1D_IN_ERROR_WIDTH 8
#define FIFO_1D_IN_FIFO_DEPTH 32
#define FIFO_1D_IN_IRQ -1
#define FIFO_1D_IN_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1D_IN_NAME "/dev/fifo_1d_in"
#define FIFO_1D_IN_SINGLE_CLOCK_MODE 1
#define FIFO_1D_IN_SPAN 4
#define FIFO_1D_IN_SYMBOLS_PER_BEAT 2
#define FIFO_1D_IN_TYPE "altera_avalon_fifo"
#define FIFO_1D_IN_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1D_IN_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1D_IN_USE_AVALONST_SINK 0
#define FIFO_1D_IN_USE_AVALONST_SOURCE 0
#define FIFO_1D_IN_USE_BACKPRESSURE 1
#define FIFO_1D_IN_USE_IRQ 0
#define FIFO_1D_IN_USE_PACKET 1
#define FIFO_1D_IN_USE_READ_CONTROL 0
#define FIFO_1D_IN_USE_REGISTER 0
#define FIFO_1D_IN_USE_WRITE_CONTROL 1


/*
 * fifo_1d_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_1d_in_csr altera_avalon_fifo
#define FIFO_1D_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_1D_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_1D_IN_CSR_BASE 0x21000
#define FIFO_1D_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_1D_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_1D_IN_CSR_ERROR_WIDTH 8
#define FIFO_1D_IN_CSR_FIFO_DEPTH 32
#define FIFO_1D_IN_CSR_IRQ -1
#define FIFO_1D_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_1D_IN_CSR_NAME "/dev/fifo_1d_in_csr"
#define FIFO_1D_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_1D_IN_CSR_SPAN 32
#define FIFO_1D_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_1D_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_1D_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_1D_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_1D_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_1D_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_1D_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_1D_IN_CSR_USE_IRQ 0
#define FIFO_1D_IN_CSR_USE_PACKET 1
#define FIFO_1D_IN_CSR_USE_READ_CONTROL 0
#define FIFO_1D_IN_CSR_USE_REGISTER 0
#define FIFO_1D_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_q_4_in_csr configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_q_4_in_csr altera_avalon_fifo
#define FIFO_Q_4_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_Q_4_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_Q_4_IN_CSR_BASE 0x8001040
#define FIFO_Q_4_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_Q_4_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_Q_4_IN_CSR_ERROR_WIDTH 8
#define FIFO_Q_4_IN_CSR_FIFO_DEPTH 32
#define FIFO_Q_4_IN_CSR_IRQ -1
#define FIFO_Q_4_IN_CSR_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_Q_4_IN_CSR_NAME "/dev/fifo_q_4_in_csr"
#define FIFO_Q_4_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_Q_4_IN_CSR_SPAN 32
#define FIFO_Q_4_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_Q_4_IN_CSR_TYPE "altera_avalon_fifo"
#define FIFO_Q_4_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_Q_4_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_Q_4_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_Q_4_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_Q_4_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_Q_4_IN_CSR_USE_IRQ 0
#define FIFO_Q_4_IN_CSR_USE_PACKET 1
#define FIFO_Q_4_IN_CSR_USE_READ_CONTROL 0
#define FIFO_Q_4_IN_CSR_USE_REGISTER 0
#define FIFO_Q_4_IN_CSR_USE_WRITE_CONTROL 1


/*
 * fifo_q_4_out configuration
 *
 */

#define ALT_MODULE_CLASS_fifo_q_4_out altera_avalon_fifo
#define FIFO_Q_4_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_Q_4_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_Q_4_OUT_BASE 0x21070
#define FIFO_Q_4_OUT_BITS_PER_SYMBOL 16
#define FIFO_Q_4_OUT_CHANNEL_WIDTH 8
#define FIFO_Q_4_OUT_ERROR_WIDTH 8
#define FIFO_Q_4_OUT_FIFO_DEPTH 32
#define FIFO_Q_4_OUT_IRQ -1
#define FIFO_Q_4_OUT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define FIFO_Q_4_OUT_NAME "/dev/fifo_q_4_out"
#define FIFO_Q_4_OUT_SINGLE_CLOCK_MODE 1
#define FIFO_Q_4_OUT_SPAN 4
#define FIFO_Q_4_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_Q_4_OUT_TYPE "altera_avalon_fifo"
#define FIFO_Q_4_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_Q_4_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_Q_4_OUT_USE_AVALONST_SINK 0
#define FIFO_Q_4_OUT_USE_AVALONST_SOURCE 0
#define FIFO_Q_4_OUT_USE_BACKPRESSURE 1
#define FIFO_Q_4_OUT_USE_IRQ 0
#define FIFO_Q_4_OUT_USE_PACKET 1
#define FIFO_Q_4_OUT_USE_READ_CONTROL 0
#define FIFO_Q_4_OUT_USE_REGISTER 0
#define FIFO_Q_4_OUT_USE_WRITE_CONTROL 1


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_1D
#define ALT_TIMESTAMP_CLK TIMER_1D


/*
 * jtag_uart_1d configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_1d altera_avalon_jtag_uart
#define JTAG_UART_1D_BASE 0x21068
#define JTAG_UART_1D_IRQ 16
#define JTAG_UART_1D_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_1D_NAME "/dev/jtag_uart_1d"
#define JTAG_UART_1D_READ_DEPTH 64
#define JTAG_UART_1D_READ_THRESHOLD 8
#define JTAG_UART_1D_SPAN 8
#define JTAG_UART_1D_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_1D_WRITE_DEPTH 64
#define JTAG_UART_1D_WRITE_THRESHOLD 8


/*
 * onchip_mem_1d configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_mem_1d altera_avalon_onchip_memory2
#define ONCHIP_MEM_1D_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEM_1D_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEM_1D_BASE 0x10000
#define ONCHIP_MEM_1D_CONTENTS_INFO ""
#define ONCHIP_MEM_1D_DUAL_PORT 0
#define ONCHIP_MEM_1D_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_1D_INIT_CONTENTS_FILE "Mega_JSoC_onchip_mem_1d"
#define ONCHIP_MEM_1D_INIT_MEM_CONTENT 1
#define ONCHIP_MEM_1D_INSTANCE_ID "NONE"
#define ONCHIP_MEM_1D_IRQ -1
#define ONCHIP_MEM_1D_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEM_1D_NAME "/dev/onchip_mem_1d"
#define ONCHIP_MEM_1D_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEM_1D_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_1D_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEM_1D_SINGLE_CLOCK_OP 0
#define ONCHIP_MEM_1D_SIZE_MULTIPLE 1
#define ONCHIP_MEM_1D_SIZE_VALUE 65536
#define ONCHIP_MEM_1D_SPAN 65536
#define ONCHIP_MEM_1D_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEM_1D_WRITABLE 1


/*
 * sysid_1d configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_1d altera_avalon_sysid_qsys
#define SYSID_1D_BASE 0x21060
#define SYSID_1D_ID 29
#define SYSID_1D_IRQ -1
#define SYSID_1D_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_1D_NAME "/dev/sysid_1d"
#define SYSID_1D_SPAN 8
#define SYSID_1D_TIMESTAMP 1718188374
#define SYSID_1D_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_1d configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1d altera_avalon_timer
#define TIMER_1D_ALWAYS_RUN 0
#define TIMER_1D_BASE 0x21040
#define TIMER_1D_COUNTER_SIZE 32
#define TIMER_1D_FIXED_PERIOD 0
#define TIMER_1D_FREQ 75000000
#define TIMER_1D_IRQ 1
#define TIMER_1D_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_1D_LOAD_VALUE 74999
#define TIMER_1D_MULT 0.0010
#define TIMER_1D_NAME "/dev/timer_1d"
#define TIMER_1D_PERIOD 1
#define TIMER_1D_PERIOD_UNITS "ms"
#define TIMER_1D_RESET_OUTPUT 0
#define TIMER_1D_SNAPSHOT 1
#define TIMER_1D_SPAN 32
#define TIMER_1D_TICKS_PER_SEC 1000.0
#define TIMER_1D_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1D_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
