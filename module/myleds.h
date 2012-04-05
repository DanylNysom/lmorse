#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

#define DEVICE_MAJOR 3333

int init_module(void);
void cleanup_module(void);
static ssize_t device_write(struct file*, const char*, size_t, loff_t*);

MODULE_LICENSE("GPL");

#define SUCCESS 0
#define DEVICE_NAME "myleds"

#define TRUE 1
#define FALSE 0

#define SCROLL_BIT 0
#define NUM_BIT 1
#define CAPS_BIT 2

#define NUM_KEY '1'
#define CAPS_KEY '2'
#define SCROLL_KEY '3'
