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
#ifndef LED_MORSE_H
#define LED_MORSE_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "arg_parsing.h"
#include "driver_control.h"


int main(int /*argc*/, char * /*argv*/ [])
	/*@globals errno, fileSystem, internalState, MAX_CHAR_LENGTH@*/
	/*@modifies errno, fileSystem, internalState@*/;

#define MAX_MESSAGE_WORDS 256


#endif
