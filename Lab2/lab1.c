#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Clayton:100824037 Zachariah::100783192 Alireza::100812651");
MODULE_DESCRIPTION("100824037 100783192 100812651: This is Group2's first Kernel module");

static int __init welcome_function(void)
{
    printk("Welcome to Systems Programming\n");
    return 0;
}

static void __exit cleaning_up_function(void)
{
    printk("Cleaning up the Kernel module");
}

module_init(welcome_function);
module_exit(cleaning_up_function);
