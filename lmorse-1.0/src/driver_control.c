#include "driver_control.h"

static FILE *driver;

void close_driver(void)
	/*@globals driver@*/
	/*@modifies *driver@*/
{
	if(fclose(driver) != 0)
	{
		/*@-unrecog@*/
		err(EXIT_FAILURE, "couldn't close driver file %s", DRIVER_FILE);
		/*@=unrecog@*/
	}	
}

void character_break(void)
{
	/*@-unrecog@*/
	(void)usleep((useconds_t)(CHAR_BREAK_LENGTH));
	/*@=unrecog@*/
}

void flash_once(char flash_type)
	/*@globals driver@*/
	/*@modifies driver@*/
{
	switch(flash_type)
	{
		case '-':
			(void)fprintf(driver, LIGHTS);
			(void)fflush(driver);
			/*@-unrecog@*/
			(void)usleep((useconds_t)(DASH_LENGTH));
			/*@=unrecog@*/
			(void)fprintf(driver, BREAK);
			(void)fflush(driver);
			break;
		case '.':
			(void)fprintf(driver, LIGHTS);
			(void)fflush(driver);
			/*@-unrecog@*/
			(void)usleep((useconds_t)(DOT_LENGTH));
			/*@=unrecog@*/
			(void)fprintf(driver, BREAK);
			(void)fflush(driver);
			break;
	}
}

void open_driver(void)
	/*@globals driver@*/
	/*@modifies driver@*/
{
	driver = fopen(DRIVER_FILE, "w");
	if(driver == NULL)
	{
		/*@-unrecog@*/
		warn("couldn't open driver file %s", DRIVER_FILE);
		/*@=unrecog@*/
		exit(EXIT_FAILURE);
	}
	else
	{
		(void)fprintf(driver, BREAK);
		(void)fflush(driver);
	}
}

void word_break(void)
{
	(void)usleep((useconds_t)(WORD_BREAK_LENGTH));
}

