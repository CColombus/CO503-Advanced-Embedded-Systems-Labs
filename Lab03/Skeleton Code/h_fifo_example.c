
#include "altera_avalon_fifo_regs.h"
#include "altera_avalon_fifo_util.h"
#include "system.h"
#include "sys/alt_irq.h"
#include <stdio.h>
#include <stdlib.h>

#define ALMOST_EMPTY 2
#define ALMOST_FULL OUTPUT_FIFO_OUT_FIFO_DEPTH - 5

volatile int input_fifo_wrclk_irq_event;

void print_status(alt_u32 control_base_address)
{
    printf("--------------------------------------\n");
    printf("LEVEL = %u\n", altera_avalon_fifo_read_level(control_base_address));
    printf("STATUS = %u\n", altera_avalon_fifo_read_status(control_base_address,
                                                           ALTERA_AVALON_FIFO_STATUS_ALL));
    printf("EVENT = %u\n", altera_avalon_fifo_read_event(control_base_address,
                                                         ALTERA_AVALON_FIFO_EVENT_ALL));
    printf("IENABLE = %u\n", altera_avalon_fifo_read_ienable(control_base_address,
                                                             ALTERA_AVALON_FIFO_IENABLE_ALL));
    printf("ALMOSTEMPTY = %u\n",
           altera_avalon_fifo_read_almostempty(control_base_address));
    printf("ALMOSTFULL = %u\n\n",
           altera_avalon_fifo_read_almostfull(control_base_address));
}

static void handle_input_fifo_wrclk_interrupts(void *context, alt_u32 id)
{
    /* Cast context to input_fifo_wrclk_irq_event's type. It is important
     * to declare this volatile to avoid unwanted compiler optimization.
     */
    volatile int *input_fifo_wrclk_irq_event_ptr = (volatile int *)context;
    /* Store the value in the FIFO's irq history register in *context. */
    *input_fifo_wrclk_irq_event_ptr =
        altera_avalon_fifo_read_event(INPUT_FIFO_IN_CSR_BASE, ALTERA_AVALON_FIFO_EVENT_ALL);
    printf("Interrupt Occurs for %#x\n", INPUT_FIFO_IN_CSR_BASE);
    print_status(INPUT_FIFO_IN_CSR_BASE);
    /* Reset the FIFO's IRQ History register. */
    altera_avalon_fifo_clear_event(INPUT_FIFO_IN_CSR_BASE,
                                   ALTERA_AVALON_FIFO_EVENT_ALL);
}

/* Initialize the fifo */
static int init_input_fifo_wrclk_control()
{
    int return_code = ALTERA_AVALON_FIFO_OK;
    /* Recast the IRQ History pointer to match the alt_irq_register() function
     * prototype. */
    void *input_fifo_wrclk_irq_event_ptr = (void *)&input_fifo_wrclk_irq_event;
    /* Enable all interrupts. */
    /* Clear event register, set enable all irq, set almostempty and
    almostfull threshold */
    return_code = altera_avalon_fifo_init(INPUT_FIFO_IN_CSR_BASE,
                                          0, // Disabled interrupts
                                          ALMOST_EMPTY,
                                          ALMOST_FULL);
    /* Register the interrupt handler. */
    alt_irq_register(INPUT_FIFO_IN_CSR_IRQ,
                     input_fifo_wrclk_irq_event_ptr, handle_input_fifo_wrclk_interrupts);
    return return_code;
}