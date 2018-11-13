#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//小写字母=大写字母+32
int main()
{
	char a = 0;
	printf("输入:");
	scanf("%c", &a);
	if (a <= 'z'&&a >= 'a')//如果是小写输出大写
		printf("%c\n", a - 32);
	else if (a <= 'Z'&&a >= 'A')
	{
		printf("%c\n", a + 32); //是大写就输出小写
	}
	system("pause");
	return 0;
}
