#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//����һ�����ַ��������������֮��
int DigitSum(int n)
{   //�ȳ���õ���λ����Ȼ���ڳ���10�õ���һ����
	if (n < 10)
	{
		return n;
	}
	else return n%10+DigitSum( n / 10);
}

int main()
{
	int n=0;
	printf("���������֣�");
	scanf("%d",&n);
	printf("%d", DigitSum(n));
	printf("\n");
	system("pause");
	return 0;
}