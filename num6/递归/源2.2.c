#include<stdio.h>
#include<stdlib.h>
int str(char* a)//char*ָ���ַ�����ĵ�һ��Ԫ�أ�Ȼ����������ʾ�ַ���
//�ַ����鱾�����һ������ֻ����ÿ��������char
{
	int count = 0;
	if (*a == '\0')//��ǰָ�����һ�����ַ�
	{
		return 0;
	}
	else
	{
		a++;//ָ����һ���ַ�
		return count= 1+ str(a);//����һ��return 1+str(a+1)
	}
	
}
int main()
{
	char* a = "nihao";
	printf("����ַ����ĳ���Ϊ %d", str(a));
	printf("\n");
	system("pause");
	return 0;
}