#include<stdio.h>
int main()
{
    long num;
    long sum = 0l;
    int status;

    printf("Please enter an integer to be summed");
    printf("(q to quit);");
    status = scanf("%ld",&num);
    //当scanf()函数成功读取对应类型的数据时，返回1，不成功返回0，读取末尾符时返回EOF(-1)
    /*当输入多个数据时，先只读取已输入的第一个数，遇到空格，tab，换行 时停止向后
    读取并返回1，之后未读取的数据会保存在输入队列里 ，再次遇到scanf()函数时读取
    输入队列的第一个数并返回1，不成功读取时返回非1，循环终止，之后数据无法再次
    遇到scanf()函数。
    */
    while (status == 1)
    {
        sum = sum + num;
        printf("Please enter next integer(q to quit):");
        status = scanf("%ld",&num);
    }
    printf("Those integers sum to %ld.\n",sum);

    return 0;
}
