#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, j;
	printf("9 * 9乘法表打印如下:\n ");
	printf("\n");
	for (i = 1; i <= 9; i++)	
	   for (j = 1; j <= i; j++)
	 {
		int sum;
		sum = j*i;
		if (i == j)
		{
			printf("%d*%d=%d\n", j, i, sum);
			printf("\n");
		}

		else
		{
			printf("%d*%d=%d\t", j, i, sum);
	   	}
	}
		system("pause");
		return 0;
}





