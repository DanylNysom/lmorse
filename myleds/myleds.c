#include "myleds.h"

static int Major;

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

static ssize_t device_write(struct file *file_p, const char *message, size_t len, loff_t *off)
{
	int retries = 5;
	int timeout = 1000;
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
		outb(2, 0x60);
	}
	return 0;
}
