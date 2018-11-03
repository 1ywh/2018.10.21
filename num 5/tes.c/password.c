#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//判断三次输密码错误则登录失败
int main()
{
	char password[1024] = {0};
	for (int i = 1; i <= 3; i++)
	{
		printf("请输入密码：\n");
		scanf("%s", password);
		if (strcmp(password, "12345") == 0)//如果输入密码相符合则成功退出循环
		{
			printf("you are success!\n");
			break;
		}
		if (i == 3)
		{
			printf("登录失败!\n");//因为三次都输入错误而结束的循环
		}
	}
	system("pause");
	return 0;
}