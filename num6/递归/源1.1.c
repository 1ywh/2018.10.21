#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//ÇónµÄ½×³Ë
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