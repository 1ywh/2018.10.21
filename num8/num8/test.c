#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>//扫雷游戏
#define ROW 9
#define COL 9
#define MINE_Count 10
//[1]先制定一个菜单
int menu()
{
	int choice = 0;
	printf("----输入1开始游戏----\n");
	printf("----输入0退出游戏----\n");
	printf("请输入你的选择：");
	scanf("%d", &choice);
	return choice;
}
//使用二维数组来表示扫雷的地图
//一个是地雷的地图minemap
//一个是展现给玩家的地图
//[1,ROW],[1,COL]为地图有效范围
// 用字符‘0’表示没有地雷，用‘1’表示周围有地雷
char minemap[ROW + 2][COL + 2];
//‘*’表示未打开的，用具体的数字表示打开的方块
char showmap[ROW + 2][COL + 2];
//【2】对地图初始化
void Init(char minemap[ROW + 2][COL + 2], char  showmap[ROW + 2][COL + 2])
{   //数组名指向数组的指针
	//对于minemap,把里面的元素初始化'0'，表示不是雷
	memset(minemap, '0', (ROW + 2)*(COL + 2));
	//对于showmap，把里面的元素初始化'*'
	memset(showmap, '*', (ROW + 2)*(COL + 2));
	//随机布置地雷
	srand((unsigned)time(0));//设置随机种子，一个程序设置一个就行
	int minecount = MINE_Count;
	while (minecount > 0)
	{
		int row = rand() % 9 + 1;//需要几个数就%几
		int col = rand() % 9 + 1;
		//每次设置一回进行  --minecount
		if (minemap[row][col] == '0')
		{
			minemap[row][col] = '1';
			minecount--;
		}
	}
}
//【3】打印地图
void Displaymap(char map[ROW + 2][COL + 2])
{  //1.打印第一行  四个空格+列的坐标
	printf("    ");
	for (int col = 1; col <= COL; col++)
	{
		printf("%d ", col);
	}
	printf("\n");
	//2.打印地图边框的内容
	for (int col = 1; col <= COL; col++)
	{
		if (col == COL)
		{
			break;
		}
		printf("---");
	}
	printf("\n");
	//3.打印地图中的具体内容
	//打印行的内容
	for (int row = 1; row <= ROW; row++)
	{
		printf("%02d| ", row);
		for (int col = 1; col <= COL; col++)
		{
			printf("%c ", map[row][col]);

		}
		printf("\n");
	}
}
//【4】统计rolw,col中共有几个雷，并更新到showmap
void Updateshowmap(char map[ROW + 2][COL + 2],
	char minemap[ROW + 2][COL + 2], int row, int col)
{
	int minecount = 0;
	if ((minemap[row - 1][col - 1] - '0')
		+ (minemap[row - 1][col] - '0')
		+ (minemap[row - 1][col + 1] - '0')
		+ (minemap[row][col - 1] - '0')
		+ (minemap[row][col + 1] - '0')
		+ (minemap[row + 1][col - 1] - '0')
		+ (minemap[row + 1][col + 1] - '0'));
	showmap[row][col] = '0' + minecount;
}
//【5】游戏开始
void game()
{
	int not_mine_count = 0;
	//1.初始化地图,布置雷阵
	Init(minemap, showmap);
	//2.打印showmap
	Displaymap(showmap);
	while (1)
	{
		//3.玩家输入坐标
		int col = 0, row = 0;
		printf("请玩家输入坐标：");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > ROW || col <= 0 || col > COL)
		{
			printf("输入有误！请重新输入：\n");
			continue;
		}
		//4.判断玩家是否踩雷若是则游戏结束打印雷阵
		if (minemap[row][col] == '1')
		{
			printf("游戏结束！\n");
			Displaymap(minemap);
			break;
		}
		//5.如果没踩雷看玩家是否胜利，就是总的个数减去地雷的个数=已经翻开了的个数
		not_mine_count++;
		if (not_mine_count == ROW*COL - MINE_Count)
		{
			printf("玩家胜利！\n");
			Displaymap(minemap);//如果胜利就打印地雷图
			break;
		}
		//6.如果当前没胜利，就说明有几个雷，并打印雷阵
		Updateshowmap(showmap, minemap, row, col);//更新雷的个数
		Displaymap(showmap);
	}
}
void start()
{
	int choice = menu();
	while (1)
	{
		if (choice == 1)
		{
			game();
		}
		else
		{
			printf("游戏结束！\n");
			break;
		}
	}
}

int main()
{
	start();
	system("pause");
	return 0;
}