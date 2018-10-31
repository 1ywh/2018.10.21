#include<stdio.h>
#include<stdlib.h>
//创造变量来交换俩个数的值
int main()
{
	int a = 3, b = 6, c;
	printf("交换之前a和b的值:  a=%d\tb=%d\n", a, b);
	c = a;
	a = b;
	b = c;
	printf("交换之后a和b的值:  a=%d\tb=%d\n", a, b);
	system("pause");
	return 0;
}