#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//递归打印整数的每一位
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ",n%10);
}
int main()
{
	int n ;
	printf("输入整数：");
	scanf("%d",&n);
	printf("输出每一位： ");
	print(n);
	system("pause");
	return 0;
}