#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 18, b = 9;
	a = a - b;  //a=a+b;
	b = a + b;  //b=a-b;
	a = b - a;  //a=a-b;
	//�������������������ķ�����ͬΪ0����Ϊ1
	//a=a^b;
	//b=a^b;
	//a=a^b;
	printf("�������ֵΪ��%d %d\n", a, b);
	system("pause");
	return 0;
}


