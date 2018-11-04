#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int str(char* a)//char*指向字符数组的第一个元素，然后用它来表示字符串
{
	int count = 0;
	while (*a != '\0')
	{
		count++;
		a++;//指向下一个字符
	}
	return count;
}
int main()
{
	char* a = "nihao";
	printf("输出字符串的长度为 %d", str(a));
	printf("\n");
    system("pause");
    return 0;
}