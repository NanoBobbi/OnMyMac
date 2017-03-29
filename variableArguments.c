// variableArguments.c
#include <stdlib.h>
#include "stdio.h"
#include "stdarg.h"
// C 语言中是通过指针的移动来读取参数列表
int sum(int count,...)
{
	int sumValue = 0;
	va_list pointer;
	// 定义一个va_list类型的指针 va 就是variable-argument(可变参数)的意思，包含在stdarg.h
	va_start(pointer,count);
	// va_start就是把指针指向参数列表中的第一个参数count
	for (int i = 0; i < count; ++i)
	{
		sumValue += va_arg(pointer,int);
		// va——arg 是按数据的类型（即类型的字节长度）将pointer向后移动，也就是参数列表的下一个参数，指针跳转后不会归位。
	}
	va_end(pointer);
	return sumValue;
}

int main(int argc, char const *argv[])
{
	int theSum = 0;
	theSum = sum(4,1,2,3,4);
	printf("%d\n", theSum);
	return 0;
}