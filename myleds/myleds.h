#include <asm/uaccess.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

int init_module(void);
void cleanup_module(void);
static ssize_t device_write(struct file*, const char*, size_t, loff_t*);

MODULE_LICENSE("GPL");

#define SUCCESS 0
#define DEVICE_NAME "myleds"
#define BUF_LEN 80

#define TRUE 1
#define FALSE 0
