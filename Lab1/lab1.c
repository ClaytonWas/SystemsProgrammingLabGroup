#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("clay:dante:zach");
MODULE_DESCRIPTION("My First Kernel Module");

static int __init welcome_function(void)
{
    printk(KERN_INFO "Welcome to my first kernel module!\n");
    return 0;
}

static void __exit cleaning_up_function(void)
{
    printk(KERN_INFO "We're cleaning up the first kernel module!");
}

module_init(welcome_function);
module_exit(cleaning_up_function);
