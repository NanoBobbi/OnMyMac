#include<stdio.h>
int main()
{
    int n;
    int index;
    //ѭ������������c++һ��������for���涨��

    scanf("%d",&n);
    int array[n];
    //c�Ķ�̬��������ڸ�ֵ���������
    //δ��ֵʱ��������
    //��̬������vc6.0���޷�����ͨ������c99֮ǰδ�涨
    for(index = 0; index <n; index++)
    {
        array[index] = 1;
        printf("the %d th array is %d\n",index,array[index]);
    }

    return 0;
}
