#ifndef TABLE_H
#define TABLE_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* The number of different characters that can be stored and output
 * (should be >= the number of lines in LETTERS_FILE
 */
/*@constant int NUM_CHARACTERS=100@*/
#define NUM_CHARACTERS 100

/* The maximum length (in '-' and '.'s of a single Characters
 */
/*@constant int MAX_CHAR_LENGTH=10@*/
#define MAX_CHAR_LENGTH 10

void build_table(/*@null@*/ char* /*file*/)
	/*@globals errno, fileSystem, internalState, MAX_CHAR_LENGTH, NUM_CHARACTERS@*/
	/*@modifies errno, fileSystem, internalState@*/;

void disable_default_translations(void)
	/*@globals internalState@*/
	/*@modifies internalState@*/;

char* retreive(char /*key*/)
	/*@globals internalState@*/;
#endif
