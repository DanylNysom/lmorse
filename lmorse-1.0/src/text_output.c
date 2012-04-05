#include "text_output.h"

#define TRUE 1
#define FALSE 0

static void output_character(char* /* morse_string */)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

static void output_word(char* /* word */)
	/*@globals errno, fileSystem, internalState@*/
	/*@modifies errno, fileSystem, internalState@*/;

void output_message(int num_words, char* words[], int do_proper)
{
	int word_number;
	if(do_proper == TRUE)
	{
		output_character(MORSE_START);
		word_break();
	}
	for(word_number = 0; word_number < num_words; word_number++)
	{
		output_word(words[word_number]);
		if(word_number+1 < num_words)
		{
			word_break();
		}
	}
	if(do_proper == TRUE)
	{
		word_break();
		output_character(MORSE_END);
	}
}

void prepare_to_output(void)
{
	open_driver();
	build_table(NULL);
}

static void output_character(char* morse_string)
{
	int char_index = 0;
	while(morse_string[char_index] != '\0')
	{
		if(char_index != 0)
		{
			(void)usleep((useconds_t)(DOT_LENGTH));
		}
		flash_once(morse_string[char_index]);
		char_index++;
	}
}

static void output_word(char* word)
{
	int index = 0;
	char morse_string[MAX_CHAR_LENGTH];
	char* value;
	morse_string[0] = '\0';
	while(word[index] != '\0')
	{
		if(index != 0)
		{
			character_break();
		}
		value = retreive(word[index]);
		strcpy(morse_string, value);
		free(value);
		output_character(morse_string);
		index++;
	}
}


