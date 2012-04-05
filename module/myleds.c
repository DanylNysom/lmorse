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
#include "myleds.h"

#ifdef MAJOR_NUMBER
static int Major = MAJOR_NUMBER;
#else
static int Major = 0;
#endif

static struct file_operations fops =
{
	.write = device_write,
};

int init_module(void)
{
	Major = register_chrdev(Major, DEVICE_NAME, &fops);
	if(Major < 0)
	{
		printk(KERN_ALERT "Registering %s failed with %d\n", DEVICE_NAME, Major);
		return Major;
	}
	printk(KERN_INFO "myleds assigned major number %d\n", Major);
	return SUCCESS;
}

void cleanup_module(void)
{
	unregister_chrdev(Major, DEVICE_NAME);
}

static ssize_t device_write(struct file *file_p, const char *input, size_t len, loff_t *off)
{
	int retries = 10;
	int timeout = 100;
	int output_message = parse_for_keys(input, len);
	outb(0xED, 0x60);
	udelay(timeout);
	while(retries != 0 && inb(0x60) != 0xFA)
	{
		retries--;
		udelay(timeout);
		printk(KERN_ALERT "Couldn't communicate with controller\n");
	}
	if(retries != 0)
	{
		outb(output_message, 0x60);
	}
	else
	{
		return -EBUSY;
	}
	return len;
}

static int parse_for_keys(const char* input, int len)
{
	int activate_light[3] = {FALSE, FALSE, FALSE};
	int index;
	int keys_sum = 0;
	for(index = 0; index < len; index++)
	{
		switch(input[index])
		{
			case NUM_KEY:
				if(activate_light[NUM_BIT] == FALSE)
				{
					activate_light[NUM_BIT] = TRUE;
					keys_sum += 1 << NUM_BIT;
				}
				break;
			case CAPS_KEY:
				if(activate_light[CAPS_BIT] == FALSE)
				{
					activate_light[CAPS_BIT] = TRUE;
					keys_sum += 1 << CAPS_BIT;
				}
				break;
			case SCROLL_KEY:
				if(activate_light[SCROLL_BIT] == FALSE)
				{
					activate_light[SCROLL_BIT] = TRUE;
					keys_sum += 1 << SCROLL_BIT;
				}
				break;
		}
	}
	return keys_sum;
}
