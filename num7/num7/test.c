#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//���һ��������ÿһλ
//225%10=5,225/10=22��22%10=2,22/10=2��2%10=2
void print(int x)
{
	if (x <=9)
	{
		printf("%d ", x % 10);
	}
	else
	{
		print(x / 10);
		printf("%d ", x % 10);
	}
}
int main()
{
	int a = 0;
	printf("����һ����:");
	scanf("%d",&a);
	print(a);
	printf("\n");
	system("pause");
	return 0;
}