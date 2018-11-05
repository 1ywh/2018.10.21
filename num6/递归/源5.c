#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//输入一个数字返回组成它的数字之和
int DigitSum(int n)
{   //先除余得到个位数字然后在除以10得到下一个数
	if (n < 10)
	{
		return n;
	}
	else return n%10+DigitSum( n / 10);
}

int main()
{
	int n=0;
	printf("请输入数字：");
	scanf("%d",&n);
	printf("%d", DigitSum(n));
	printf("\n");
	system("pause");
	return 0;
}