#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//���Լ��
int main()
{
	int a ,b,c,z ;
	printf("��������������");
	scanf("%d %d", &a, &b);//������������
	printf("�����������Լ��Ϊ�� ");
	if (b < a)
	{
		z = a; a = b; b = z;//�жϴ�С
	}
	else 
	while  (b%a != 0)//������
	{
		c=b%a ;
		b = a;
	    a = c;//���Լ�����ǵõ���a
	}
    printf("%d \n ", a);//������Լ��
	system("pause");
	return 0;
}