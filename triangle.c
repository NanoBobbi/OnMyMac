#include<stdio.h>
void triangle(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n-i;j++)  putchar(' ');
		for(j=0;j<=2*i;j++) putchar('*');
		putchar('\n');

	}
}
int main(int argc,char* const argv[])
{
	int n;
	printf("Please enter n:");
	scanf("%d",&n);
	printf("\n");
	triangle(n);
	return 0;
}
