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

