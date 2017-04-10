// This C file shows the meaning of argc and argv in main arguments.

/*argc means the 'arguments count',it counts its argument passed to the main().
  argv means the 'arguments vector',it`s argument names passed to the main.
  这两个名字不同当然所代表的意思也就不同。我刚开始看到这就吓到了，主要是中文太博大精深了，整这样的简称太专业了，把人都绕晕了。从英文解释或中文全称看就比较容易理解。

	指针数组：array of pointers，即用于存储指针的数组，也就是数组元素都是指针

	数组指针：a pointer to an array，即指向数组的指针

	还要注意的是他们用法的区别，下面举例说明。

	int* a[4]     指针数组

	                 表示：数组a中的元素都为int型指针

	                 元素表示：*a[i]   *(a[i])是一样的，因为[]优先级高于*

	int (*a)[4]   数组指针

	                 表示：指向数组a的指针

	                 元素表示：(*a)[i]
*/
#include "stdio.h"

int main(int argc, char const *argv[])
{
	printf("%d \n",argc );
	for (int i = 0; i < argc; ++i)
	{
		printf("%s \n", *(argv + i));
	}
	return 0;
}
