#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int SXH_Count(int num)
{
	int temp = num;
	if (num<100 || num>999)
		return 0;//��������������0
	int num1 = num % 10;//ȡ����λ
	num = num / 10;
	int num2 = num % 10;//ȡ��ʮλ
	num = num / 10;
	int num3 = num % 10; //ȡ����λ
	if (temp == pow(num1, 3) + pow(num2, 3) + pow(num3, 3))
		return 1;
	return 0;
}
int main()
{
	int num;
	for (num = 100; num < 1000; num++)
	{
		if (SXH_Count(num))
			printf("%d\n", num);
	}
    system("pause");
	return 0;
}

	