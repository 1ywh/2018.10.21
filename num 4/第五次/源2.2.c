#include<stdio.h>
#include<stdlib.h>
//打印左对齐菱形
int main()
{
int i, a, b;
for (i = 1; i <= 7; i++)//先打印前7行
{
	for (b = 1; b <= 2 * i - 1; b++)
		printf("*");
	for (a = 1; a <= 13-b+1 ; a++)//这一步其实可以没有
			printf("");
		printf("\n");	
}
for (i = 6; i > 0; i--)//打印后6行
{
	for (b = 1; b <= 2 * i - 1; b++)
		printf("*");
	printf("\n");
}
	system("pause");
	return 0;
}