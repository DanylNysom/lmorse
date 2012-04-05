#include "arg_parsing.h"

#define TRUE 1
#define FALSE 0

#ifdef PACKAGE_STRING
/*@unused@*/ const char* argp_program_version = PACKAGE_STRING;
#else
/*@unused@*/ const char* argp_program_version = "lmorse 1.0";
#endif

#ifdef PACKAGE_BUGREPORT
/*@unused@*/ const char* argp_program_bug_address = PACKAGE_BUGREPORT;
#else
/*@unused@*/ const char* argp_program_bug_address = "<danyl.nysom@gmail.com>";
#endif

static int parse_opt(int /*key*/, char* /*arg*/, struct argp_state* /*state*/)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

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

