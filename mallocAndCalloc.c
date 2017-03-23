// mallocAndCalloc.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *ptr1,*ptr2;
	ptr1 = (int*)malloc(5*sizeof(int));
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ",*(ptr1 + i) );
	}
	putchar('\n');

	ptr2 = (int*)calloc(5,sizeof(int));
	for (int i = 0; i < 5; ++i)
	{
		printf("%d ",*(ptr2 + i) );
	}
	putchar('\n');

	return 0;
}