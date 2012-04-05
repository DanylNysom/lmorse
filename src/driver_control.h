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
#ifndef DRIVER_CONTROL_H
#define DRIVER_CONTROL_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* The length of a 'dit' (in microseconds)
 */
#define DOT_LENGTH (0.2 * 1000000)

#define DASH_LENGTH (3 * DOT_LENGTH)
#define CHAR_BREAK_LENGTH (3 * DOT_LENGTH)
#define WORD_BREAK_LENGTH (7 * DOT_LENGTH)

#define DRIVER_FILE "/dev/myleds"

/********** Light Control **********/

/* Which lights to flash:
 * 	1 is num lock
 * 	2 is caps lock
 * 	3 is scroll lock
 *
 * e.g. To flash num and caps lock, put "12" here
 */
#define LIGHTS "123"

/* The message to send the driver to turn the lights off
 * Can be anything that doesn't include 1, 2, or 3
 * (unless you want a light to flash during the breaks)
 */
#define BREAK "x"

/********** End Light Control **********/

/* Closes the driver file
 */
void close_driver(void)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

/* Pauses for CHAR_BREAK_LENGTH microseconds, the duration of
 * time between separate characters of a word in morse code.
 * Precondition:
 * 	The driver has been opened previously
 */
void character_break(void)
	/*@modifies@*/;

/* Flashes the LEDs specified by LIGHTS, depending on flash_type.
 * If flash_type is '-', the lights will be flashed for the
 * duration of a morse code dash (DASH_LENGTH microseconds).
 * If flash_type is '.', the lights will be flashed for the
 * duration of a dit.
 * Precondition:
 * 	The driver has been opened previously
 */
void flash_once(char /* flash_type */)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

/* Opens the driver file. This should be executed before
 * any other function in this file.
 * Precondition:
 * 	The driver file needs to have been created for this to work
 */
void open_driver(void)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;
	
/* Pauses for WORD_BREAK_LENGTH microseconds, the duration of
 * time between separate words of a message in morse code.
 * Precondition:
 * 	The driver has been opened previously
 */
void word_break(void)
	/*@modifies@*/;

#endif
