#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//�ݹ���쳲�������
int fib(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return fib(n-2)+fib(n-1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("���%d��쳲��������� ", n);
	printf("%d", fib( n));
	system("pause");
	return 0;
}