#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//最大公约数
int main()
{
	int a ,b,c,z ;
	printf("请输入俩个数：");
	scanf("%d %d", &a, &b);//先输入俩个数
	printf("俩个数的最大公约数为： ");
	if (b < a)
	{
		z = a; a = b; b = z;//判断大小
	}
	else 
	while  (b%a != 0)//求余数
	{
		c=b%a ;
		b = a;
	    a = c;//最大公约数就是得到的a
	}
    printf("%d \n ", a);//输出最大公约数
	system("pause");
	return 0;
}