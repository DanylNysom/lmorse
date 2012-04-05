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
 * 	0 is scroll lock
 * 	1 is num lock
 * 	2 is caps lock
 *
 * e.g. To flash num and caps lock, put "12" here
 */
#define LIGHTS "2"

/* The message to send the driver to turn the lights off
 * Can be anything that doesn't include 0, 1, or 2
 */
#define BREAK "1"

/********** End Light Control **********/


void close_driver(void)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

void character_break(void)
	/*@modifies@*/;

void flash_once(char /* flash_type */)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

void open_driver(void)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;
	
void word_break(void)
	/*@modifies@*/;

#endif
