//素数
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j;
	printf("100--200之间的素数有：\n");
	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j < i; j++)
		if (i%j == 0)break;//如果能被整除则不是素数结束循环，不整除的话继续执行直到j>i
		if (j == i)printf("%d\t", i);
	}
	system("pause");
	return 0;
}