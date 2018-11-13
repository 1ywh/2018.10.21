#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>//ɨ����Ϸ
#define ROW 9
#define COL 9
#define MINE_Count 10
//[1]���ƶ�һ���˵�
int menu()
{
	int choice = 0;
	printf("----����1��ʼ��Ϸ----\n");
	printf("----����0�˳���Ϸ----\n");
	printf("���������ѡ��");
	scanf("%d", &choice);
	return choice;
}
//ʹ�ö�ά��������ʾɨ�׵ĵ�ͼ
//һ���ǵ��׵ĵ�ͼminemap
//һ����չ�ָ���ҵĵ�ͼ
//[1,ROW],[1,COL]Ϊ��ͼ��Ч��Χ
// ���ַ���0����ʾû�е��ף��á�1����ʾ��Χ�е���
char minemap[ROW + 2][COL + 2];
//��*����ʾδ�򿪵ģ��þ�������ֱ�ʾ�򿪵ķ���
char showmap[ROW + 2][COL + 2];
//��2���Ե�ͼ��ʼ��
void Init(char minemap[ROW + 2][COL + 2], char  showmap[ROW + 2][COL + 2])
{   //������ָ�������ָ��
	//����minemap,�������Ԫ�س�ʼ��'0'����ʾ������
	memset(minemap, '0', (ROW + 2)*(COL + 2));
	//����showmap���������Ԫ�س�ʼ��'*'
	memset(showmap, '*', (ROW + 2)*(COL + 2));
	//������õ���
	srand((unsigned)time(0));//����������ӣ�һ����������һ������
	int minecount = MINE_Count;
	while (minecount > 0)
	{
		int row = rand() % 9 + 1;//��Ҫ��������%��
		int col = rand() % 9 + 1;
		//ÿ������һ�ؽ���  --minecount
		if (minemap[row][col] == '0')
		{
			minemap[row][col] = '1';
			minecount--;
		}
	}
}
//��3����ӡ��ͼ
void Displaymap(char map[ROW + 2][COL + 2])
{  //1.��ӡ��һ��  �ĸ��ո�+�е�����
	printf("    ");
	for (int col = 1; col <= COL; col++)
	{
		printf("%d ", col);
	}
	printf("\n");
	//2.��ӡ��ͼ�߿������
	for (int col = 1; col <= COL; col++)
	{
		if (col == COL)
		{
			break;
		}
		printf("---");
	}
	printf("\n");
	//3.��ӡ��ͼ�еľ�������
	//��ӡ�е�����
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
//��4��ͳ��rolw,col�й��м����ף������µ�showmap
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
//��5����Ϸ��ʼ
void game()
{
	int not_mine_count = 0;
	//1.��ʼ����ͼ,��������
	Init(minemap, showmap);
	//2.��ӡshowmap
	Displaymap(showmap);
	while (1)
	{
		//3.�����������
		int col = 0, row = 0;
		printf("������������꣺");
		scanf("%d %d", &row, &col);
		if (row <= 0 || row > ROW || col <= 0 || col > COL)
		{
			printf("�����������������룺\n");
			continue;
		}
		//4.�ж�����Ƿ������������Ϸ������ӡ����
		if (minemap[row][col] == '1')
		{
			printf("��Ϸ������\n");
			Displaymap(minemap);
			break;
		}
		//5.���û���׿�����Ƿ�ʤ���������ܵĸ�����ȥ���׵ĸ���=�Ѿ������˵ĸ���
		not_mine_count++;
		if (not_mine_count == ROW*COL - MINE_Count)
		{
			printf("���ʤ����\n");
			Displaymap(minemap);//���ʤ���ʹ�ӡ����ͼ
			break;
		}
		//6.�����ǰûʤ������˵���м����ף�����ӡ����
		Updateshowmap(showmap, minemap, row, col);//�����׵ĸ���
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
			printf("��Ϸ������\n");
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