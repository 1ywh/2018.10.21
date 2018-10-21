#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>//打印一个三子棋
#define ROW 3
#define COL 3
//1.首先用二维数组来表示一个棋盘
char g_chess_board[ROW][COL];
//2.对棋盘初始化(初始化为空格)
void set_word()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			g_chess_board[i][j] = ' ';
		}
	}
}
//3.打印棋盘
void print_chessboard()
//可以直接用一个for循环
{
	for (int i = 0; i < ROW; i++)
	{
		printf("| %c| %c| %c|\n", g_chess_board[i][0],
			g_chess_board[i][1], g_chess_board[i][2]);
		if (i != ROW - 1)//让边缘不打印，满足条件打印
		{
			printf("|--|--|--|\n");
		}
	}
}
//这种方法适用于行列比较多的
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			printf("| %c", g_chess_board[i][j]);
//			if (j == 2)
//				printf("|\n");
//		}
//		if (i != ROW - 1)//让边缘不打印，满足条件打印
//			printf("|--|--|--|\n");
//	}
//}
void playerbegin()//玩家输入，并对玩家输入的进行检
{
	int row = 0;
	int col = 0;
	while (1)
	{
		printf("请God输入行和列:");//1.提示玩家输入
		scanf("%d %d", &row, &col);
		//2.对玩家的输入进行验证
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("输入有误请重新输入：\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ')//如果当前有子
		{
			printf("当前有子！重新输入：\n");
			continue;
		}
		g_chess_board[row][col] = 'a';//a表示玩家落子
		break;
	}
}
void computerbegin()//o表示电脑落子
{
	int row = 0;
	int col = 0;
	printf("电脑落子\n");//电脑落子随机
	while (1)
	{
		row = rand() % ROW;//相当于求余数在[0,2]范围
		col = rand() % COL;
		if (g_chess_board[row][col] == ' ')
		{
			g_chess_board[row][col] = 'o';
			break;
		}
	}
}
int equal()//看是否平局
{
	for (int row = 0; row < ROW; row++)
	{
		for (int col = 0; col < COL; col++)
		{
			if (g_chess_board[row][col] == ' ')
			{
				return 0;
			}
		}
	}//满了返回1
	return 1;
}
//返回a表示玩家胜利，返回o表示电脑胜利
char checkwinner()
{
	int w = 0;
	//1.看行是否连在一起	   
	for (int row = 0; row < ROW; row++)
	{
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0] != ' ')
		{
			return g_chess_board[row][0];
		}
	}
	//2.看列是否连在一起
	for (int col = 0; col < COL; col++)
	{
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' ')
		{
			return g_chess_board[0][col];
		}
	}
	//看俩条对角线是否连在一起
	if (g_chess_board[0][0] == g_chess_board[1][1]
		&& g_chess_board[0][0] == g_chess_board[2][2]
		&& g_chess_board[0][0] != ' ')
	{
		return g_chess_board[0][0];
	}
	if (g_chess_board[0][2] == g_chess_board[1][1]
		&& g_chess_board[0][2] == g_chess_board[2][0]
		&& g_chess_board[0][2] != ' ')
	{
		return g_chess_board[0][2];
	}
	//看是否平局
	if (equal())
	{
		return w;
	}//返回w表示结果未知
	else return ' ';
}
int main()
{
	char winner = ' ';
	set_word();//给棋盘设置初值
	while (1)//每次开始都要打印棋盘
	{
		print_chessboard();//打印棋盘
		playerbegin();//玩家落子
		winner = checkwinner();//落之后检验看游戏是否结束
		if (winner != ' ')//不是空格说明是o或w或a则游戏结束
		{
			break;
		}
		computerbegin();//电脑落子
		winner = checkwinner();
		//落之后检验看游戏是否结束
		if (winner != ' ')
		{
			break;
		}
	}
	if (winner == 'a')//玩家胜利
		printf("玩家胜利！\n");
	else
	{
		if (winner == 'o')//电脑胜利
		{
			printf("电脑胜利！\n");
		}

		else
		{
			if (winner == 'w')//结果未知
				printf("平局！\n");
		}
	}
	//或者之间用一个if俩个 else if
	system("pause");
	return 0;
}