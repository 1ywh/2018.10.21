#include<stdio.h>
#include<stdlib.h>
int str(char* a)//char*指向字符数组的第一个元素，然后用它来表示字符串
//字符数组本身就是一个数组只不过每个类型是char
{
	int count = 0;
	if (*a == '\0')//当前指向的是一个空字符
	{
		return 0;
	}
	else
	{
		a++;//指向下一个字符
		return count= 1+ str(a);//或者一步return 1+str(a+1)
	}
	
}
int main()
{
	char* a = "nihao";
	printf("输出字符串的长度为 %d", str(a));
	printf("\n");
	system("pause");
	return 0;
}