#ifndef LED_MORSE_H
#define LED_MORSE_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "arg_parsing.h"
#include "driver_control.h"


int main (int /*argc*/, char * /*argv*/ [])
	/*@globals errno, fileSystem, internalState, MAX_CHAR_LENGTH@*/
	/*@modifies errno, fileSystem, internalState@*/;

#define MIN_ALLOWABLE_ARGS 1
#define MAX_MESSAGE_WORDS 256


#endif
