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
#ifndef TABLE_H
#define TABLE_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* The number of different characters that can be stored and output
 * (should be >= the number of lines in the translations file),
 * otherwise the program will just terminate without flashing
 * the LEDs.
 */
#ifndef NUM_CHARACTERS
#define NUM_CHARACTERS 100
#endif

/* The maximum length (in '-' and '.'s of a single Characters
 */
#ifndef MAX_CHAR_LENGTH
#define MAX_CHAR_LENGTH 10
#endif

/* Adds to the table the character-to-morse translations from the given translations
 * file. The file should contain data in the format:
 * <character> <translation>
 * where the <translation> contains only '-'s and '.'s
 * If 'file' is NULL, the default translations file will be used
 */
void build_table(/*@null@*/char* /*file*/)
	/*@globals errno, fileSystem, internalState, MAX_CHAR_LENGTH, NUM_CHARACTERS@*/
	/*@modifies errno, fileSystem, internalState@*/;

/* Makes it so the default translations file will not be used at all for the current
 * execution, even if build_table(NULL) is called.
 * This will only do anything if the default file has not already been used. It will
 * not removed any translations that have already been processed.
 */
void disable_default_translations(void)
	/*@globals internalState@*/
	/*@modifies internalState@*/;

/* Returns the morse string (in the form of '-'s and '.'s) corresponding to the given
 * key. The key should just be the ASCII value of the desired character, as that is
 * how this implementation currently stores the translations. Eventually I may make
 * it fancier.
 */
char* retreive(char /*key*/)
	/*@globals internalState@*/;

#endif
