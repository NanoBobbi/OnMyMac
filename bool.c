#include<stdio.h>
int main()
{
    long num;
    long sum = 0l;
    _Bool input_is_good;
    //可以换成int类型
    //或引用stdbool.h库 使用bool,true,false

    printf("Please enter an integer to be summed ");
    printf("(q to quit):");
    input_is_good = (scanf("%ld",&num) == 1);
    //scanf()函数 外面的括号可以不要，因为 == 运算符优先级高于 =
    // = 优先级比很多运算符都低
    // expression 'a==b',return 0 or 1,right or wrong
    // >,<,<=,>=,!= is also the same
    while (input_is_good)
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit):");
        input_is_good = (scanf("%ld",&num) == 1);
    }
    printf("Those integers sum to %ld.\n",sum);

    return 0;
}
