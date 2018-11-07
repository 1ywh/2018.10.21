#include<stdio.h>
#include<stdlib.h>
//获取一个数二进制序列中所有的偶数位和奇数位 
//分别输出二进制序列
void print(int n)
{
	//获取一个数二进制序列中所有的偶数位
	for (int i = 31; i >0 ; i = i - 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	//获取一个数二进制序列中所有的奇数位
	for (int i = 30; i >= 0; i = i - 2)
	{
		printf("%d", (n >> i) & 1);
	}
}
int main()
{
	int a = 10;
	print(a);
    system("pause");
    return 0;
}
