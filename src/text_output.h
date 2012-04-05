/*  Dylan Symons: lmorse - Flashes the keyboard LEDs in morse code
    Copyright (C) 2012  Dylan Symons

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
