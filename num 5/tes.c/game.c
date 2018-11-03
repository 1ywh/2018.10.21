#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//猜数字游戏
int menu()//先定义一个菜单，函数1
{
	printf("=========================================\n");
	printf("              1.开始游戏                 \n");
	printf("              0.开始游戏                 \n");
	printf("=========================================\n");
	printf("请输入您的选择\n");
	int chance = 0;
	scanf("%d", &chance);//完成选择的输入
	return chance;
}
void game()
{
	int result = rand() % 100 + 1;//函数2
	while (1)//一直执行循环直到成功
	{
		int num = 0;
		printf("请输入你的数字：\n");
		scanf("%d", &num);
		if (num > result)
			printf("高了|\n");
		else if (num < result)
         printf("低了\n");
		else
		{
			printf("恭喜你！\n");
			break;
		}
	}
	
}
int main()
{
	while (1)//因为要用break所以使用这个循环
	{
		int chance = menu();//调用函数输入选项
		if (chance == 1)
		{
			printf("开始游戏\n");//1的时候开始游戏
			game();
			break; //游戏完后就不进行
		}
		else if (chance == 0)
		{
			printf("结束游戏\n");
			break;
		}
		else printf("输入有误请重新输入：\n");//这时继续执行循环
	}
	system("pause");
	return 0;
}



	