/*
 * 	FIFO header for shared memory communication between niosII processors
 *
 *  	DATE		: 18-08-2016
 *      AUTHOR	: Isuru Nawinne
*
*	Structure of the FIFO:
*	___________________________________________________________________________
*	| 	full	| 	empty	| 	count		|	|	|	|	|	|	|	|	|
*	| 	?	| 	?		| 	?		|	|	|	|	|	|	|	|	|
*	___________________________________________________________________________
*/


//CHANGE THESE NAMES FOR DIFFERENT FIFOS
#ifndef FIFO_1_H_
#define FIFO_1_H_


#include <io.h>
#include "system.h"
#include <stdio.h>
#include <altera_avalon_fifo_regs.h>
#include <altera_avalon_fifo_util.h>


#define MEM_BASE 0x00041050			// Base address of the FIFO
#define CTRL_BASE 0x00041000		// Base address of the Control/Status Register


//CHANGE THE NAME FOR DIFFERENT FIFOS
void WRITE_FIFO_1(int *buffer);

//CHANGE THE NAME FOR DIFFERENT FIFOS
void READ_FIFO_1(int *buffer);


#endif /* FIFO_1_H_ */