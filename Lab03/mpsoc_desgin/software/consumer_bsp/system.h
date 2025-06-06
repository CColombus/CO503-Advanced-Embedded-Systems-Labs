/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu1' in SOPC Builder design 'mpsoc'
 * SOPC Builder design path: D:/SEM6/CO503/Lab03/mpsoc_desgin/mpsoc.sopcinfo
 *
 * Generated: Fri May 24 19:29:53 IST 2024
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
#define ALT_CPU_BREAK_ADDR 0x00040820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x13
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00020020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x13
#define ALT_CPU_NAME "cpu1"
#define ALT_CPU_RESET_ADDR 0x00020000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00040820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x13
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00020020
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
#define NIOS2_INST_ADDR_WIDTH 0x13
#define NIOS2_RESET_ADDR 0x00020000


/*
 * Define for each module class mastered by the CPU
 *
 */

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
#define ALT_STDERR "/dev/jtag_uart_1"
#define ALT_STDERR_BASE 0x41028
#define ALT_STDERR_DEV jtag_uart_1
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_1"
#define ALT_STDIN_BASE 0x41028
#define ALT_STDIN_DEV jtag_uart_1
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_1"
#define ALT_STDOUT_BASE 0x41028
#define ALT_STDOUT_DEV jtag_uart_1
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "mpsoc"


/*
 * alt_timer_1 configuration
 *
 */

#define ALT_MODULE_CLASS_alt_timer_1 altera_avalon_timer
#define ALT_TIMER_1_ALWAYS_RUN 0
#define ALT_TIMER_1_BASE 0x0
#define ALT_TIMER_1_COUNTER_SIZE 32
#define ALT_TIMER_1_FIXED_PERIOD 0
#define ALT_TIMER_1_FREQ 50000000
#define ALT_TIMER_1_IRQ 20
#define ALT_TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define ALT_TIMER_1_LOAD_VALUE 49
#define ALT_TIMER_1_MULT 1.0E-6
#define ALT_TIMER_1_NAME "/dev/alt_timer_1"
#define ALT_TIMER_1_PERIOD 1
#define ALT_TIMER_1_PERIOD_UNITS "us"
#define ALT_TIMER_1_RESET_OUTPUT 0
#define ALT_TIMER_1_SNAPSHOT 1
#define ALT_TIMER_1_SPAN 32
#define ALT_TIMER_1_TICKS_PER_SEC 1000000.0
#define ALT_TIMER_1_TIMEOUT_PULSE_OUTPUT 0
#define ALT_TIMER_1_TYPE "altera_avalon_timer"


/*
 * data_mem_shared configuration
 *
 */

#define ALT_MODULE_CLASS_data_mem_shared altera_avalon_onchip_memory2
#define DATA_MEM_SHARED_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define DATA_MEM_SHARED_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define DATA_MEM_SHARED_BASE 0x60000
#define DATA_MEM_SHARED_CONTENTS_INFO ""
#define DATA_MEM_SHARED_DUAL_PORT 0
#define DATA_MEM_SHARED_GUI_RAM_BLOCK_TYPE "AUTO"
#define DATA_MEM_SHARED_INIT_CONTENTS_FILE "mpsoc_data_mem_shared"
#define DATA_MEM_SHARED_INIT_MEM_CONTENT 1
#define DATA_MEM_SHARED_INSTANCE_ID "NONE"
#define DATA_MEM_SHARED_IRQ -1
#define DATA_MEM_SHARED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DATA_MEM_SHARED_NAME "/dev/data_mem_shared"
#define DATA_MEM_SHARED_NON_DEFAULT_INIT_FILE_ENABLED 0
#define DATA_MEM_SHARED_RAM_BLOCK_TYPE "AUTO"
#define DATA_MEM_SHARED_READ_DURING_WRITE_MODE "DONT_CARE"
#define DATA_MEM_SHARED_SINGLE_CLOCK_OP 0
#define DATA_MEM_SHARED_SIZE_MULTIPLE 1
#define DATA_MEM_SHARED_SIZE_VALUE 131072
#define DATA_MEM_SHARED_SPAN 131072
#define DATA_MEM_SHARED_TYPE "altera_avalon_onchip_memory2"
#define DATA_MEM_SHARED_WRITABLE 1


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER_1
#define ALT_TIMESTAMP_CLK ALT_TIMER_1


/*
 * ins_mem_c1 configuration
 *
 */

#define ALT_MODULE_CLASS_ins_mem_c1 altera_avalon_onchip_memory2
#define INS_MEM_C1_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define INS_MEM_C1_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define INS_MEM_C1_BASE 0x20000
#define INS_MEM_C1_CONTENTS_INFO ""
#define INS_MEM_C1_DUAL_PORT 0
#define INS_MEM_C1_GUI_RAM_BLOCK_TYPE "AUTO"
#define INS_MEM_C1_INIT_CONTENTS_FILE "mpsoc_ins_mem_c1"
#define INS_MEM_C1_INIT_MEM_CONTENT 1
#define INS_MEM_C1_INSTANCE_ID "NONE"
#define INS_MEM_C1_IRQ -1
#define INS_MEM_C1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INS_MEM_C1_NAME "/dev/ins_mem_c1"
#define INS_MEM_C1_NON_DEFAULT_INIT_FILE_ENABLED 0
#define INS_MEM_C1_RAM_BLOCK_TYPE "AUTO"
#define INS_MEM_C1_READ_DURING_WRITE_MODE "DONT_CARE"
#define INS_MEM_C1_SINGLE_CLOCK_OP 0
#define INS_MEM_C1_SIZE_MULTIPLE 1
#define INS_MEM_C1_SIZE_VALUE 131072
#define INS_MEM_C1_SPAN 131072
#define INS_MEM_C1_TYPE "altera_avalon_onchip_memory2"
#define INS_MEM_C1_WRITABLE 1


/*
 * jtag_uart_1 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_1 altera_avalon_jtag_uart
#define JTAG_UART_1_BASE 0x41028
#define JTAG_UART_1_IRQ 16
#define JTAG_UART_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_1_NAME "/dev/jtag_uart_1"
#define JTAG_UART_1_READ_DEPTH 64
#define JTAG_UART_1_READ_THRESHOLD 8
#define JTAG_UART_1_SPAN 8
#define JTAG_UART_1_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_1_WRITE_DEPTH 64
#define JTAG_UART_1_WRITE_THRESHOLD 8


/*
 * sysid_1 configuration
 *
 */

#define ALT_MODULE_CLASS_sysid_1 altera_avalon_sysid_qsys
#define SYSID_1_BASE 0x41020
#define SYSID_1_ID 193
#define SYSID_1_IRQ -1
#define SYSID_1_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_1_NAME "/dev/sysid_1"
#define SYSID_1_SPAN 8
#define SYSID_1_TIMESTAMP 1716558762
#define SYSID_1_TYPE "altera_avalon_sysid_qsys"


/*
 * timer_1 configuration
 *
 */

#define ALT_MODULE_CLASS_timer_1 altera_avalon_timer
#define TIMER_1_ALWAYS_RUN 0
#define TIMER_1_BASE 0x41000
#define TIMER_1_COUNTER_SIZE 32
#define TIMER_1_FIXED_PERIOD 0
#define TIMER_1_FREQ 50000000
#define TIMER_1_IRQ 1
#define TIMER_1_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_1_LOAD_VALUE 49999
#define TIMER_1_MULT 0.0010
#define TIMER_1_NAME "/dev/timer_1"
#define TIMER_1_PERIOD 1
#define TIMER_1_PERIOD_UNITS "ms"
#define TIMER_1_RESET_OUTPUT 0
#define TIMER_1_SNAPSHOT 1
#define TIMER_1_SPAN 32
#define TIMER_1_TICKS_PER_SEC 1000.0
#define TIMER_1_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_1_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
