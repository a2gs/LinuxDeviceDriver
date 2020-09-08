/* from: https://static.lwn.net/images/pdf/LDD3/ch02.pdf with my modifications */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("LDD3 and a2gs");

static int param1 = 13;
static char *param2 = "andre augusto giannotti scota";

module_param(param1, int, S_IRUGO);
module_param(param2, charp, S_IRUGO);

MODULE_PARM_DESC(param1, "An integer parameter.");
MODULE_PARM_DESC(param2, "A char * parameter.");

static int hello_init(void)
{
	printk(KERN_ALERT "Hello world! (param1 = [%d], param2 = [%s])\n", param1, param2);

	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);
