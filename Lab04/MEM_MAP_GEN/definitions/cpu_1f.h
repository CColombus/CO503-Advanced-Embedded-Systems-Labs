#ifndef _ALTERA_CPU_1F_H_
#define _ALTERA_CPU_1F_H_

/*
 * This file was automatically generated by the swinfo2header utility.
 * 
 * Created from SOPC Builder system 'FTOP_MSOC' in
 * file '../SUPERSCALAR_18/FTOP_MSOC.sopcinfo'.
 */

/*
 * This file contains macros for module 'cpu_1f' and devices
 * connected to the following masters:
 *   data_master
 *   instruction_master
 * 
 * Do not include this header file and another header file created for a
 * different module or master group at the same time.
 * Doing so may result in duplicate macro names.
 * Instead, use the system header file which has macros with unique names.
 */

/*
 * Macros for module 'cpu_1f', class 'altera_nios2_gen2'.
 * The macros have no prefix.
 */
#define BIG_ENDIAN 0
#define BREAK_ADDR 0x1020
#define CPU_ARCH_NIOS2_R1 
#define CPU_FREQ 75000000
#define CPU_ID_SIZE 1
#define CPU_ID_VALUE 0x00000000
#define CPU_IMPLEMENTATION "tiny"
#define DATA_ADDR_WIDTH 28
#define DCACHE_LINE_SIZE 0
#define DCACHE_LINE_SIZE_LOG2 0
#define DCACHE_SIZE 0
#define EXCEPTION_ADDR 0x8020020
#define FLASH_ACCELERATOR_LINES 0
#define FLASH_ACCELERATOR_LINE_SIZE 0
#define FLUSHDA_SUPPORTED 
#define HARDWARE_DIVIDE_PRESENT 0
#define HARDWARE_MULTIPLY_PRESENT 0
#define HARDWARE_MULX_PRESENT 0
#define HAS_DEBUG_CORE 1
#define HAS_DEBUG_STUB 
#define HAS_ILLEGAL_INSTRUCTION_EXCEPTION 
#define HAS_JMPI_INSTRUCTION 
#define ICACHE_LINE_SIZE 0
#define ICACHE_LINE_SIZE_LOG2 0
#define ICACHE_SIZE 0
#define INST_ADDR_WIDTH 28
#define OCI_VERSION 1
#define RESET_ADDR 0x8020000

/*
 * Macros for device 'timer_1f', class 'altera_avalon_timer'
 * The macros are prefixed with 'TIMER_1F_'.
 * The prefix is the slave descriptor.
 */
#define TIMER_1F_COMPONENT_TYPE altera_avalon_timer
#define TIMER_1F_COMPONENT_NAME timer_1f
#define TIMER_1F_BASE 0x0
#define TIMER_1F_SPAN 32
#define TIMER_1F_END 0x1f
#define TIMER_1F_IRQ 1
#define TIMER_1F_ALWAYS_RUN 0
#define TIMER_1F_COUNTER_SIZE 32
#define TIMER_1F_FIXED_PERIOD 0
#define TIMER_1F_FREQ 75000000
#define TIMER_1F_LOAD_VALUE 74999
#define TIMER_1F_MULT 0.001
#define TIMER_1F_PERIOD 1
#define TIMER_1F_PERIOD_UNITS ms
#define TIMER_1F_RESET_OUTPUT 0
#define TIMER_1F_SNAPSHOT 1
#define TIMER_1F_TICKS_PER_SEC 1000
#define TIMER_1F_TIMEOUT_PULSE_OUTPUT 0

/*
 * Macros for device 'sysid_1f', class 'altera_avalon_sysid_qsys'
 * The macros are prefixed with 'SYSID_1F_'.
 * The prefix is the slave descriptor.
 */
#define SYSID_1F_COMPONENT_TYPE altera_avalon_sysid_qsys
#define SYSID_1F_COMPONENT_NAME sysid_1f
#define SYSID_1F_BASE 0x20
#define SYSID_1F_SPAN 8
#define SYSID_1F_END 0x27
#define SYSID_1F_ID 31
#define SYSID_1F_TIMESTAMP 1719041505

/*
 * Macros for device 'jtag_uart_1f', class 'altera_avalon_jtag_uart'
 * The macros are prefixed with 'JTAG_UART_1F_'.
 * The prefix is the slave descriptor.
 */
#define JTAG_UART_1F_COMPONENT_TYPE altera_avalon_jtag_uart
#define JTAG_UART_1F_COMPONENT_NAME jtag_uart_1f
#define JTAG_UART_1F_BASE 0x28
#define JTAG_UART_1F_SPAN 8
#define JTAG_UART_1F_END 0x2f
#define JTAG_UART_1F_IRQ 16
#define JTAG_UART_1F_READ_DEPTH 64
#define JTAG_UART_1F_READ_THRESHOLD 8
#define JTAG_UART_1F_WRITE_DEPTH 64
#define JTAG_UART_1F_WRITE_THRESHOLD 8

/*
 * Macros for device 'fifo_qe_out', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_QE_OUT_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_QE_OUT_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_QE_OUT_COMPONENT_NAME fifo_qe
#define FIFO_QE_OUT_BASE 0x30
#define FIFO_QE_OUT_SPAN 4
#define FIFO_QE_OUT_END 0x33
#define FIFO_QE_OUT_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_QE_OUT_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_QE_OUT_BITS_PER_SYMBOL 16
#define FIFO_QE_OUT_CHANNEL_WIDTH 8
#define FIFO_QE_OUT_ERROR_WIDTH 8
#define FIFO_QE_OUT_FIFO_DEPTH 32
#define FIFO_QE_OUT_SINGLE_CLOCK_MODE 1
#define FIFO_QE_OUT_SYMBOLS_PER_BEAT 2
#define FIFO_QE_OUT_USE_AVALONMM_READ_SLAVE 1
#define FIFO_QE_OUT_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_QE_OUT_USE_AVALONST_SINK 0
#define FIFO_QE_OUT_USE_AVALONST_SOURCE 0
#define FIFO_QE_OUT_USE_BACKPRESSURE 1
#define FIFO_QE_OUT_USE_IRQ 0
#define FIFO_QE_OUT_USE_PACKET 1
#define FIFO_QE_OUT_USE_READ_CONTROL 0
#define FIFO_QE_OUT_USE_REGISTER 0
#define FIFO_QE_OUT_USE_WRITE_CONTROL 1

/*
 * Macros for device 'fifo_qe_in_csr', class 'altera_avalon_fifo'
 * The macros are prefixed with 'FIFO_QE_IN_CSR_'.
 * The prefix is the slave descriptor.
 */
#define FIFO_QE_IN_CSR_COMPONENT_TYPE altera_avalon_fifo
#define FIFO_QE_IN_CSR_COMPONENT_NAME fifo_qe
#define FIFO_QE_IN_CSR_BASE 0x60
#define FIFO_QE_IN_CSR_SPAN 32
#define FIFO_QE_IN_CSR_END 0x7f
#define FIFO_QE_IN_CSR_AVALONMM_AVALONMM_DATA_WIDTH 32
#define FIFO_QE_IN_CSR_AVALONMM_AVALONST_DATA_WIDTH 32
#define FIFO_QE_IN_CSR_BITS_PER_SYMBOL 16
#define FIFO_QE_IN_CSR_CHANNEL_WIDTH 8
#define FIFO_QE_IN_CSR_ERROR_WIDTH 8
#define FIFO_QE_IN_CSR_FIFO_DEPTH 32
#define FIFO_QE_IN_CSR_SINGLE_CLOCK_MODE 1
#define FIFO_QE_IN_CSR_SYMBOLS_PER_BEAT 2
#define FIFO_QE_IN_CSR_USE_AVALONMM_READ_SLAVE 1
#define FIFO_QE_IN_CSR_USE_AVALONMM_WRITE_SLAVE 1
#define FIFO_QE_IN_CSR_USE_AVALONST_SINK 0
#define FIFO_QE_IN_CSR_USE_AVALONST_SOURCE 0
#define FIFO_QE_IN_CSR_USE_BACKPRESSURE 1
#define FIFO_QE_IN_CSR_USE_IRQ 0
#define FIFO_QE_IN_CSR_USE_PACKET 1
#define FIFO_QE_IN_CSR_USE_READ_CONTROL 0
#define FIFO_QE_IN_CSR_USE_REGISTER 0
#define FIFO_QE_IN_CSR_USE_WRITE_CONTROL 1

/*
 * Macros for device 'mem_info', class 'altera_avalon_onchip_memory2'
 * The macros are prefixed with 'MEM_INFO_'.
 * The prefix is the slave descriptor.
 */
#define MEM_INFO_COMPONENT_TYPE altera_avalon_onchip_memory2
#define MEM_INFO_COMPONENT_NAME mem_info
#define MEM_INFO_BASE 0x10000
#define MEM_INFO_SPAN 1024
#define MEM_INFO_END 0x103ff
#define MEM_INFO_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define MEM_INFO_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define MEM_INFO_CONTENTS_INFO ""
#define MEM_INFO_DUAL_PORT 0
#define MEM_INFO_GUI_RAM_BLOCK_TYPE AUTO
#define MEM_INFO_INIT_CONTENTS_FILE FTOP_MSOC_mem_info
#define MEM_INFO_INIT_MEM_CONTENT 1
#define MEM_INFO_INSTANCE_ID NONE
#define MEM_INFO_NON_DEFAULT_INIT_FILE_ENABLED 0
#define MEM_INFO_RAM_BLOCK_TYPE AUTO
#define MEM_INFO_READ_DURING_WRITE_MODE DONT_CARE
#define MEM_INFO_SINGLE_CLOCK_OP 0
#define MEM_INFO_SIZE_MULTIPLE 1
#define MEM_INFO_SIZE_VALUE 1024
#define MEM_INFO_WRITABLE 1
#define MEM_INFO_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define MEM_INFO_MEMORY_INFO_GENERATE_DAT_SYM 1
#define MEM_INFO_MEMORY_INFO_GENERATE_HEX 1
#define MEM_INFO_MEMORY_INFO_HAS_BYTE_LANE 0
#define MEM_INFO_MEMORY_INFO_HEX_INSTALL_DIR QPF_DIR
#define MEM_INFO_MEMORY_INFO_MEM_INIT_DATA_WIDTH 32
#define MEM_INFO_MEMORY_INFO_MEM_INIT_FILENAME FTOP_MSOC_mem_info

/*
 * Macros for device 'sdram_controller', class 'altera_avalon_new_sdram_controller'
 * The macros are prefixed with 'SDRAM_CONTROLLER_'.
 * The prefix is the slave descriptor.
 */
#define SDRAM_CONTROLLER_COMPONENT_TYPE altera_avalon_new_sdram_controller
#define SDRAM_CONTROLLER_COMPONENT_NAME sdram_controller
#define SDRAM_CONTROLLER_BASE 0x8000000
#define SDRAM_CONTROLLER_SPAN 134217728
#define SDRAM_CONTROLLER_END 0xfffffff
#define SDRAM_CONTROLLER_CAS_LATENCY 3
#define SDRAM_CONTROLLER_CONTENTS_INFO 
#define SDRAM_CONTROLLER_INIT_NOP_DELAY 0.0
#define SDRAM_CONTROLLER_INIT_REFRESH_COMMANDS 2
#define SDRAM_CONTROLLER_IS_INITIALIZED 1
#define SDRAM_CONTROLLER_POWERUP_DELAY 100.0
#define SDRAM_CONTROLLER_REFRESH_PERIOD 15.625
#define SDRAM_CONTROLLER_REGISTER_DATA_IN 1
#define SDRAM_CONTROLLER_SDRAM_ADDR_WIDTH 25
#define SDRAM_CONTROLLER_SDRAM_BANK_WIDTH 2
#define SDRAM_CONTROLLER_SDRAM_COL_WIDTH 10
#define SDRAM_CONTROLLER_SDRAM_DATA_WIDTH 32
#define SDRAM_CONTROLLER_SDRAM_NUM_BANKS 4
#define SDRAM_CONTROLLER_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_CONTROLLER_SDRAM_ROW_WIDTH 13
#define SDRAM_CONTROLLER_SHARED_DATA 0
#define SDRAM_CONTROLLER_SIM_MODEL_BASE 0
#define SDRAM_CONTROLLER_STARVATION_INDICATOR 0
#define SDRAM_CONTROLLER_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_CONTROLLER_T_AC 6.0
#define SDRAM_CONTROLLER_T_MRD 3
#define SDRAM_CONTROLLER_T_RCD 20.0
#define SDRAM_CONTROLLER_T_RFC 70.0
#define SDRAM_CONTROLLER_T_RP 20.0
#define SDRAM_CONTROLLER_T_WR 14.0
#define SDRAM_CONTROLLER_MEMORY_INFO_DAT_SYM_INSTALL_DIR SIM_DIR
#define SDRAM_CONTROLLER_MEMORY_INFO_GENERATE_DAT_SYM 1
#define SDRAM_CONTROLLER_MEMORY_INFO_MEM_INIT_DATA_WIDTH 32


#endif /* _ALTERA_CPU_1F_H_ */
