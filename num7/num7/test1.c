#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//求二进制中1的个数
//方法一，不能用于负数
void count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		if (value % 2 == 1)
		count++;
		//不管是0还是1都进入下一位
		value >>= 1; 
	}
	printf("%d",count);
}
int main()
{
	int num = 10;
	count_one_bits(num);
	printf("\n");
    system("pause");
    return 0;
}
int main()
{
	int value;
	scanf("%d",&value);
	 count_one_bits(value);
    system("pause");
    return 0;
}