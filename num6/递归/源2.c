#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int str(char* a)//char*ָ���ַ�����ĵ�һ��Ԫ�أ�Ȼ����������ʾ�ַ���
{
	int count = 0;
	while (*a != '\0')
	{
		count++;
		a++;//ָ����һ���ַ�
	}
	return count;
}
int main()
{
	char* a = "nihao";
	printf("����ַ����ĳ���Ϊ %d", str(a));
	printf("\n");
    system("pause");
    return 0;
}