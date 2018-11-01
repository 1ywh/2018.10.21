#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//水仙花的个数
int main()
{
	int n, i, j, k;
	for (n = 100; n <= 999; n++)
	{
		i = n / 100;//百位
		k = n % 10;//个位
		j = n / 10 % 10;//十位

		if (pow(i, 3) + pow(j, 3) + pow(k, 3) == n)
			printf("%d\n", n);
	}
	system("pause");
	return 0;
}