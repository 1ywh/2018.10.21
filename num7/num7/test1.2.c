#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//���������1�ĸ���
//������
void count_one_bits(unsigned int value)
{
	int count = 0;
	for (int i = 1; i != 0; i <<= 1)//i�����ж�ѭ������
	{
		if ((value & 1) == 1)
			count++;
		value >>= 1;
	}
	printf("%d", count);
}
int main()
{
	int value;
	scanf("%d", &value);
	count_one_bits(value);
	system("pause");
	return 0;
}