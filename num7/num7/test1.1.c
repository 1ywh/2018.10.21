#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//求二进制中1的个数
//方法二
//1000 >> 1 = 0100
void count_one_bits(unsigned int value)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (value & (1 << i))//或者if((value>>i)&1==1)
		{
			count++;
		}
	}
	printf("%d", count);
}
int main()
{
	int value;
	scanf("%d", &value);
	count_one_bits(value);
	system("pause");
	return 0;
}