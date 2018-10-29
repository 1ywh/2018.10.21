#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//最大公约数
int MaxFactor(int x, int y)
{
	int i = 1, max = 1;
	while (i <= x && i <= y)
	{
		if (x%i == 0 && y%i == 0)
			max = i;
		i++;
	}
	return max;
}int main()
{
	int max, x, y;
	scanf("%d %d", &x, &y);
	max = MaxFactor(x, y);
	printf("%d", max);
	system("pause");
	return 0;
}
