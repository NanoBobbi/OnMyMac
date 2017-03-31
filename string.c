#include<stdio.h>
#define PRAISE "You are an extraordinary being."
//#define不是语句而是预处理命令，不需要类型或者分号
int main(int argc,char const *argv[])
{
	char name[40];
	//字符串以字符数组的方式存储在内存中
	char b = '6';
	int a = 10;
	printf("%d",b);
	//字符和整型可以相互表示，对应anscll表
	//printf("%f",a);
	//整型无法用浮点型表示

	printf("What`s your name?");
	scanf("%s",name);
	//输入的字符串只会读取第一个单词，遇到空格就会停止
	printf("Hello, %s.%s\n",name,PRAISE);
	//字符串用字符表示都为空，因为最后一个字符为终止符，这也是字符和字符串的区别

	size = sizeof(name);
	//带不带括号都一样

	letters = strlen(name);
	//strlen()函数遇到终止符就停止计数，不计入终止符
	printf("also,your first name has %d letters,\n and we have %d bytes to store it.\n",letters,size);

}
