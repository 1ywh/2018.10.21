#include<stdio.h>
#include<stdlib.h>
//��ӡ���������
int main()
{
int i, a, b;
for (i = 1; i <= 7; i++)//�ȴ�ӡǰ7��
{
	for (b = 1; b <= 2 * i - 1; b++)
		printf("*");
	for (a = 1; a <= 13-b+1 ; a++)//��һ����ʵ����û��
			printf("");
		printf("\n");	
}
for (i = 6; i > 0; i--)//��ӡ��6��
{
	for (b = 1; b <= 2 * i - 1; b++)
		printf("*");
	printf("\n");
}
	system("pause");
	return 0;
}