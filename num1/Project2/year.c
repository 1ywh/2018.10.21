#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int year;
	scanf("%d", &year);
	/*if (year % 4 == 0)
	{
	if (year % 100 == 0)
	{
	if (year % 400 == 0)
	printf("yes");
	else
	printf("no");
	}
	else printf("yes");
	}
	else printf("no");*/
	int n, count = 0;
	printf("1000到2000的闰年有:\n");
	for (n = 1000; n <= 2000; n++, count++)
	if (n % 4 == 0)
	{
		if (n % 100 == 0)
		{
			if (n % 400 == 0)
			{
				printf("%d\t", n);
			}
		}
		else printf("%d\t", n);
	}
	printf("\n闰年有%d个\n", count);

	/*if (year % 4 == 0)
	{
	if (year % 100 != 0)
	printf("yes");
	else
	{
	if (year % 400 == 0)
	printf("yes");
	else
	printf("no");
	}
	}
	else printf("no");*/
	system("pause");
	return 0;
}





