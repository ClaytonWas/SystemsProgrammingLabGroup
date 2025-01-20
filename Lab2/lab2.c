#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Clayton:100824037 Zachariah::100783192 Alireza::100812651");
MODULE_DESCRIPTION("100824037 100783192 100812651: This is Group2's second Kernel module");

static int __init lab02_init(void) {
    printk(KERN_INFO "This is the second Systems Programming Lab\n");
    return 0;
}

static void __exit lab02_exit(void) {
    printk(KERN_INFO "Cleaning up the Kernel Module\n");
}

module_init(lab02_init);
module_exit(lab02_exit);