#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 18, b = 9;
	a = a - b;  //a=a+b;
	b = a + b;  //b=a-b;
	a = b - a;  //a=a-b;
	//方法二，按二进制异或的方法相同为0相异为1
	//a=a^b;
	//b=a^b;
	//a=a^b;
	printf("交换后的值为：%d %d\n", a, b);
	system("pause");
	return 0;
}


