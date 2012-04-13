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
#include "table.h"

/* This should be detected automatically */
static const char* rcdir = "/usr/local/etc/";

static char table[NUM_CHARACTERS][MAX_CHAR_LENGTH];

static char* translations_file = "lmorse_translations";

/* 
 */
static char* get_infile_name(char* /* infile */);

/* Inserts the given key-value pair into the table.
 * Preconditions:
 * 	Value is not NULL
 * 	key is >= 0
 */
static void insert(int /* key */, char* /* value */)
	/*@globals table@*/
	/*@modifies table@*/;

/* Converts the given character to uppercase. The only
 * characters that are modified are those which were originally
 * lowercase alphabet characters (a-z). Everything else will be
 * left untouched.
 */
static char to_uppercase(char /*original*/);

void build_table(char* infile)
	/*@globals table, translations_file@*/
	/*@modifies *(table[])*/
{
	char key;
	char value[MAX_CHAR_LENGTH];
	FILE *data_file;
	int i;
	char* file = NULL;
	file = get_infile_name(infile);

	if((data_file = fopen(file, "r")) == NULL)
	{
		warn("unable to open translations file '%s'", file);
		exit(EXIT_FAILURE);
	}
	free(file);

	for(i = 0; i < NUM_CHARACTERS; i++)
	{
		strcpy(table[i], "");
	}

	while(fscanf(data_file, "%c %[.-]\n", &key, value) > 0)
	{
		key = to_uppercase(key);
		insert((int)key, value);
	}
	if(fclose(data_file) != 0)
	{
		err(EXIT_FAILURE, "unable to close translations file '%s'", file);
	}	
}

void disable_default_translations(void)
	/*@globals translations_file@*/
	/*@modifies translations_file@*/
{
	translations_file = NULL;
}

char* retreive(char key)
	/*@globals table@*/
{
	char *value = malloc(sizeof(table[0]));
	if(value == NULL)
	{
		err(EXIT_FAILURE, "malloc failure");
	}
	key = to_uppercase(key);
	strncpy(value, table[(int)key % NUM_CHARACTERS], sizeof(value));
	return value;
}

static char* get_infile_name(char* infile)
{
	char* file = NULL;
	if(infile != NULL)
	{
		file = malloc(strlen(infile) + 1);
		if(file == NULL)
		{
			fprintf(stderr, "Out of memory, won't add any more translations\n");
			return;
		}
		strcpy(file, infile);
	}
	else
	{
		file = malloc(strlen(translations_file) + strlen(rcdir) + 1);
		if(file == NULL)
		{
			fprintf(stderr, "Out of memory, won't add any more translations\n");
			return;
		}
		strcpy(file, rcdir);
		strcat(file, translations_file);
		if(access(translations_file, R_OK) == -1)
		{
			sprintf(file, "%s%s", rcdir, translations_file);
		}
	}
	return file;
}


static void insert(int key, char value[])
{
	char tmp[MAX_CHAR_LENGTH];
	strcpy(tmp, value);
	if(strcmp(table[key % NUM_CHARACTERS], "") == 0)
	{
		strcpy(table[key % NUM_CHARACTERS], tmp);
	}
	else
	{
		errx(EXIT_FAILURE, "unable to insert '%s' with key %d, terminating", value, key);
	}
}

static char to_uppercase(char original)
{
	/*@-strictops@*/
	if((unsigned int)(original - 'a') < (unsigned int)'z')
	{
		return original + 'A' - 'a';
	/*@=strictops@*/
	}
	else
	{
		return original;
	}
}
