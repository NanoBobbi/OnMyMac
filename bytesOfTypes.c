/*
bytesOfTypes.c
	测试环境：macOS 10.12.4 Unix x64
	测试工具：clang Xcode 8.3
	测试日期：2017，3，29
	测试内容：查看C语言中常用类型的字节数
*/

#include <string.h>
#include <stdio.h>

int main(int argc,char const* argv[])
{
	/*三种基本的整型类型*/
	// short 2字节 16位
	printf("%8s:%lu bytes\n","short", sizeof(short));
	// int 4字节 32位
	printf("%8s:%lu bytes\n","int", sizeof(int));
	// long 8字节 64位
	printf("%8s:%lu bytes\n","long", sizeof(long));

	putchar('\n');
	/*基本的浮点类型*/
	// float 4字节 32位
	printf("%8s:%lu bytes\n","float", sizeof(float));
	// double 8字节 64位
	printf("%8s:%lu bytes\n","double", sizeof(double));

	putchar('\n');
	/*字符型*/
	// char1字节 8位
	printf("%8s:%lu bytes\n","char", sizeof(char));

    return 0;
}