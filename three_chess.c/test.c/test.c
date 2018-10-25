#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>//��ӡһ��������
#define ROW 3
#define COL 3
//1.�����ö�ά��������ʾһ������
char g_chess_board[ROW][COL];
//2.�����̳�ʼ��(��ʼ��Ϊ�ո�)
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
//3.��ӡ����
void print_chessboard()
//����ֱ����һ��forѭ��
{
	for (int i = 0; i < ROW; i++)
	{
		printf("| %c| %c| %c|\n", g_chess_board[i][0],
			g_chess_board[i][1], g_chess_board[i][2]);
		if (i != ROW - 1)//�ñ�Ե����ӡ������������ӡ
		{
			printf("|--|--|--|\n");
		}
	}
}
//���ַ������������бȽ϶��
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			printf("| %c", g_chess_board[i][j]);
//			if (j == 2)
//				printf("|\n");
//		}
//		if (i != ROW - 1)//�ñ�Ե����ӡ������������ӡ
//			printf("|--|--|--|\n");
//	}
//}
void playerbegin()//������룬�����������Ľ��м�
{
	int row = 0;
	int col = 0;
	while (1)
	{
		printf("��God�����к���:");//1.��ʾ�������
		scanf("%d %d", &row, &col);
		//2.����ҵ����������֤
		if (row < 0 || row >= ROW || col < 0 || col >= COL)
		{
			printf("�����������������룺\n");
			continue;
		}
		if (g_chess_board[row][col] != ' ')//�����ǰ����
		{
			printf("��ǰ���ӣ��������룺\n");
			continue;
		}
		g_chess_board[row][col] = 'a';//a��ʾ�������
		break;
	}
}
void computerbegin()//o��ʾ��������
{
	int row = 0;
	int col = 0;
	printf("��������\n");//�����������
	while (1)
	{
		row = rand() % ROW;//�൱����������[0,2]��Χ
		col = rand() % COL;
		if (g_chess_board[row][col] == ' ')
		{
			g_chess_board[row][col] = 'o';
			break;
		}
	}
}
int equal()//���Ƿ�ƽ��
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
	}//���˷���1
	return 1;
}
//����a��ʾ���ʤ��������o��ʾ����ʤ��
char checkwinner()
{
	int w = 0;
	//1.�����Ƿ�����һ��	   
	for (int row = 0; row < ROW; row++)
	{
		if (g_chess_board[row][0] == g_chess_board[row][1]
			&& g_chess_board[row][0] == g_chess_board[row][2]
			&& g_chess_board[row][0] != ' ')
		{
			return g_chess_board[row][0];
		}
	}
	//2.�����Ƿ�����һ��
	for (int col = 0; col < COL; col++)
	{
		if (g_chess_board[0][col] == g_chess_board[1][col]
			&& g_chess_board[0][col] == g_chess_board[2][col]
			&& g_chess_board[0][col] != ' ')
		{
			return g_chess_board[0][col];
		}
	}
	//�������Խ����Ƿ�����һ��
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
	//���Ƿ�ƽ��
	if (equal())
	{
		return w;
	}//����w��ʾ���δ֪
	else return ' ';
}
int main()
{
	char winner = ' ';
	set_word();//���������ó�ֵ
	while (1)//ÿ�ο�ʼ��Ҫ��ӡ����
	{
		print_chessboard();//��ӡ����
		playerbegin();//�������
		winner = checkwinner();//��֮����鿴��Ϸ�Ƿ����
		if (winner != ' ')//���ǿո�˵����o��w��a����Ϸ����
		{
			break;
		}
		computerbegin();//��������
		winner = checkwinner();
		//��֮����鿴��Ϸ�Ƿ����
		if (winner != ' ')
		{
			break;
		}
	}
	if (winner == 'a')//���ʤ��
		printf("���ʤ����\n");
	else
	{
		if (winner == 'o')//����ʤ��
		{
			printf("����ʤ����\n");
		}

		else
		{
			if (winner == 'w')//���δ֪
				printf("ƽ�֣�\n");
		}
	}
	//����֮����һ��if���� else if
	system("pause");
	return 0;
}