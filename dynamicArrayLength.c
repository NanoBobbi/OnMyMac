#include<stdio.h>
int main()
{
    int n;
    int index;
    //循环迭代器不像c++一样可以在for里面定义

    scanf("%d",&n);
    int array[n];
    //c的动态数组必须在赋值后才能声明
    //未赋值时程序会崩溃
    //动态数组在vc6.0内无法编译通过，在c99之前未规定
    for(index = 0; index <n; index++)
    {
        array[index] = 1;
        printf("the %d th array is %d\n",index,array[index]);
    }

    return 0;
}
