#include<stdio.h>
#include<stdlib.h>
//打印菱形
void lingxing(int black, int star)//负责打印空格和星号
{
	for (int row = 1; row <= black; row++)//打印空格
	{
		printf(" ");
	}
	for (int row = 1; row <= star; row++)//打印星号
	{
		printf("*");
	}
	printf("\n");
}
void  printlingxing(int n)//打印菱形图案分俩步
{
	for (int row = 1; row <= n; row++)//先将上半部分打出来
	{
		printf("%d\t", 2 * row - 1);
		lingxing(n - row, 2 * row - 1);
	}//先找到规律空格数=n-row，星号数=2*row-1
	for (int row = n - 1; row > 0; row--)//将下半部分打印出来
	{
		printf("%d\t", 2 * row - 1);
		lingxing(n - row, 2 * row - 1);
	}
}
int main()
{
	printlingxing(7);
	printf("\n");
    system("pause");
	return 0;
}