#include<stdio.h>
#include<stdlib.h>
//��ӡ����
void lingxing(int black, int star)//�����ӡ�ո���Ǻ�
{
	for (int row = 1; row <= black; row++)//��ӡ�ո�
	{
		printf(" ");
	}
	for (int row = 1; row <= star; row++)//��ӡ�Ǻ�
	{
		printf("*");
	}
	printf("\n");
}
void  printlingxing(int n)//��ӡ����ͼ��������
{
	for (int row = 1; row <= n; row++)//�Ƚ��ϰ벿�ִ����
	{
		printf("%d\t", 2 * row - 1);
		lingxing(n - row, 2 * row - 1);
	}//���ҵ����ɿո���=n-row���Ǻ���=2*row-1
	for (int row = n - 1; row > 0; row--)//���°벿�ִ�ӡ����
	{
		printf("%d\t", 2 * row - 1);
		lingxing(n - row, 2 * row - 1);
	}
}
int main()
{
	printlingxing(7);
	printf("\n");
    system("pause");
	return 0;
}