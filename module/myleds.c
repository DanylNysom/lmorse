#include "myleds.h"

#ifdef DEVICE_MAJOR
static int Major = DEVICE_MAJOR;
#else
static int Major = 0;
#endif

static struct file_operations fops = {.write = device_write};

int init_module(void)
{
	Major = register_chrdev(0, DEVICE_NAME, &fops);
	if(Major < 0)
	{
		printk(KERN_ALERT "Registering %s failed with %d\n", DEVICE_NAME, Major);
		return Major;
	}
	printk(KERN_INFO "I was assigned major number %d\n", Major);
	return SUCCESS;
}

void cleanup_module(void)
{
	unregister_chrdev(Major, DEVICE_NAME);
}

static ssize_t device_write(struct file *file_p, const char *input, size_t len, loff_t *off)
{
	int retries = 5;
	int timeout = 1000;
	int activate_light[3] = {FALSE, FALSE, FALSE};
	int output_message = 0;
	int index;
	for(index = 0; index < len; index++)
	{
		switch(input[index])
		{
			case NUM_KEY:
				if(activate_light[NUM_BIT] == FALSE)
				{
					activate_light[NUM_BIT] = TRUE;
					output_message += 1 << NUM_BIT;
				}
				break;
			case CAPS_KEY:
				if(activate_light[CAPS_BIT] == FALSE)
				{
					activate_light[CAPS_BIT] = TRUE;
					output_message += 1 << CAPS_BIT;
				}
				break;
			case SCROLL_KEY:
				if(activate_light[SCROLL_BIT] == FALSE)
				{
					activate_light[SCROLL_BIT] = TRUE;
					output_message += 1 << SCROLL_BIT;
				}
				break;
		}
	}
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
