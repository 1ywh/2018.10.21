#include<stdio.h>
#include<stdlib.h>
//��ȡһ�������������������е�ż��λ������λ 
//�ֱ��������������
void print(int n)
{
	//��ȡһ�������������������е�ż��λ
	for (int i = 31; i >0 ; i = i - 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	//��ȡһ�������������������е�����λ
	for (int i = 30; i >= 0; i = i - 2)
	{
		printf("%d", (n >> i) & 1);
	}
}
int main()
{
	int a = 10;
	print(a);
    system("pause");
    return 0;
}
