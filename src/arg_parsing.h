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
#ifndef ARG_PARSING_H
#define ARG_PARSING_H

#include <argp.h>
#include "config.h"
#include "table.h"
#include "text_output.h"

/* Essentially controls the entire program. Everything the program does is
 * affected by the command line arguments, which are parsed here. Any options
 * (starting with '-') will be dealt with as specified by their given meaning,
 * such as '--help' for help output. Any non-options that start with a '-' will
 * simply be ignored.
 *
 * Preconditions:
 * 	argv must not be NULL
 * 	argc should contain the number of valid entries in argv. Mayble less, but
 * 	definitely not more. These should just be taken from those passed to main().
 */
void parse_options(int /*argc*/, char* /*argv*/[])
	/*@globals internalState@*/;

#endif
