#ifndef TEXT_OUTPUT_H
#define TEXT_OUTPUT_H

#include <stdio.h>
#include <unistd.h>
#include "driver_control.h"
#include "table.h"

/********** Special Morse Characters **********/

#define MORSE_END "...-.-"
#define MORSE_ERROR "........"
#define MORSE_START "-.-.-" 
#define MORSE_TRANSMIT "-.-"
#define MORSE_UNDERSTOOD "...-."
#define MORSE_WAIT ".-..."

/********** End Special Morse Characters **********/


void output_message(int /*num_words*/, char* /*words*/[], int /*do_proper*/)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

void prepare_to_output(void)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;



#endif
