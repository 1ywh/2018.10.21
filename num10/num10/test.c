#include<stdio.h>
#include<stdlib.h>
#define N 10
//��ӡ�������
//��һ�к�ÿһ�е����һ�����ֶ���1
//��������ֶ����Ϸ�������֮��
//���õݹ��������
int print(int row,int col)
{
	int sum = 0;
	if (col == row||col==1)
		return sum = 1; 
	else
	{
		return print(row - 1, col-1) + print(row - 1, col);
	}
	
}
int main()
{
	for (int row = 1; row <= N; row++)
	{
		for (int col = 1; col <= 4 * (N - row) / 2; col++)

			printf(" ");

		for (int col = 1; col <= row; col++)
		{

			printf("%4d ", print(row, col));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}




