#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//��n�Ľ׳�
int main()
{
	int i,n,sum=1;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum *= i;
	}
	printf("%d!=%d", n, sum);
	system("pause");
	return 0;
}