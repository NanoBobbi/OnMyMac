/* C语言中如何使用printf()函数来显示不同的进制 */
#include<stdio.h>
int main(int argc, char const *argv[])
{
    printf("the octal digit is %o \n",16);
    //%o 代表octal(base 8)八进制数 在数值前面会加一个0进行标识
    printf("the decimal digit is %d \n",16);
    printf("the decimal digit is %d \n",016);
    printf("the decimal digit is %d \n",0x16);
    //%d 代表decimal（base 10）十进制数 数值前面无任何标识
    //要使数值显示0 或 0x 前缀 要写成%#o 或 %#x
    printf("the hexadecimal digit is %x\n",16);
    //%x 代表hexadecimal (base 16)十六进制数 数值面前会加0x或0X
    //超出数字部分用a~f表示
    printf("the hexadecimal digit is %#o\n",16);
    printf("the hexadecimal digit is %#x\n",16);
    return 0;
}
