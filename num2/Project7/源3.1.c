#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, b;
	printf("请输入十个整数：");
	int max[20] = { 8, 7, 6, 9, 5, 4, 34, 75, 88, 46 };
	for (i = 0; i < 10; i++)
		printf("%d  ", max[i]);
	for (i = 0; i < 9; i++)
	if (max[i] >= max[i + 1])
	{
		b = max[i];
		max[i] = max[i + 1];
		max[i + 1] = b;
	}
	printf("\n十个数中最大的是：%d \n ", max[i]);
	system("pause");
	return 0;
}