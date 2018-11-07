#include<stdio.h>
#include<stdlib.h>
//输出两个int（32位）整数m和n的二进制表达
//有多少个位(bit)不同
void dif(int n, int m)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{    //逐个去比较每一个二进制位
		if (((m >> i)&1)!=((n>>i)&1))
			count++;
	}
	printf("%d\n",count);
}
int main()
{
	dif(1999,2299);
	system("pause");
	return 0;
}