#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//ˮ�ɻ��ĸ���
int main()
{
	int n, i, j, k;
	for (n = 100; n <= 999; n++)
	{
		i = n / 100;//��λ
		k = n % 10;//��λ
		j = n / 10 % 10;//ʮλ

		if (pow(i, 3) + pow(j, 3) + pow(k, 3) == n)
			printf("%d\n", n);
	}
	system("pause");
	return 0;
}