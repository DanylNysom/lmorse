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
#include "arg_parsing.h"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifdef PACKAGE_STRING
const char* argp_program_version = PACKAGE_STRING;
#else
const char* argp_program_version = "lmorse";
#endif

#ifdef PACKAGE_BUGREPORT
const char* argp_program_bug_address = PACKAGE_BUGREPORT;
#else
const char* argp_program_bug_address = "<danyl.nysom@gmail.com>";
#endif

/* The argp parsing function to be used in argp_parse. This will use the options
 * specified in the argp_option options[] array of structs to parse the command
 * line for options, and the message to be output. It really shouldn't be used
 * anywhere else.
 */
static int parse_opt(int /*key*/, char* /*arg*/, struct argp_state* /*state*/)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;


/* The valid command-line options for this program, to be used by argp
 */
static struct argp_option options[] =
{
	/*@-type@*/
	{"proper", 'p', 0, 0,
		"Do 'proper' morse output, with the start- and end-of-transmission characters output", 0},
	{"translations-file", 't', "FILE", 0,
		"Read translations from FILE instead of the default translations file, can specify multiple with seperate -t flags", 0},
	{0, 0, 0, 0, 0, 0}
	/*@=type@*/
};


void parse_options(int argc, char* argv[])
	/*@globals options@*/
{
	char doc[] = "lmorse -- Flashes the keyboard LEDs in morse code";
	char args_doc[] = "MESSAGE";
	struct argp parser;
	parser.options = options;
	parser.parser = parse_opt;
	parser.args_doc = args_doc;
	parser.doc = doc;
	parser.children = NULL;
	parser.help_filter = 0;
	parser.argp_domain = 0;
	/*@-unrecog@*/
	argp_parse(&parser, argc, argv, 0, 0, 0);
	/*@=unrecog@*/
}

static int parse_opt(int key, char *arg, struct argp_state *state)
{
	static int num_words = 0;
	static int do_proper = FALSE;
	switch(key)
	{
		case 'p':
			do_proper = TRUE;
			break;
		case 't':
			disable_default_translations();
			build_table(arg);
			break;
		/*@-unrecog@*/
		case ARGP_KEY_ARGS:
		/*@=unrecog@*/
			prepare_to_output();
			num_words = (*state).argc - (*state).next;
			output_message(num_words, (*state).argv + (*state).next, do_proper);
			return 0;
		/*@-unrecog@*/
		case ARGP_KEY_END:
		/*@=unrecog@*/
			if(num_words == 0)
			{
				/*@-unrecog@*/
				argp_usage(state);
				/*@=unrecog@*/
			}
			return 0;
		default:
			/*@-unrecog@*/
			return ARGP_ERR_UNKNOWN;
			/*@=unrecog@*/
	}
	return 0;
}

