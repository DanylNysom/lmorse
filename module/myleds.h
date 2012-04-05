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
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

/* Initializes the module by registering it with the OS
 */
int init_module(void);

/* Unregisters the module from the OS
 */
void cleanup_module(void);

/* Toggles the keyboard lock key LEDs based on 'input', as follows:
 * 	If a '1' is in the input, the num lock light will be turned on
 * 	If a '2' is in the input, the caps lock light will be turned on
 * 	If a '3' is in the input, the scroll lock light will be turned on
 * 	If none of 1, 2, and/or 3 were in the input, all lights will be off
 */
static ssize_t device_write(struct file*, const char* /*input*/, size_t, loff_t*);

static int parse_for_keys(const char* input, int len);

MODULE_LICENSE("GPL");

#define SUCCESS 0
#define DEVICE_NAME "myleds"

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define SCROLL_BIT 0
#define NUM_BIT 1
#define CAPS_BIT 2

#define NUM_KEY '1'
#define CAPS_KEY '2'
#define SCROLL_KEY '3'
