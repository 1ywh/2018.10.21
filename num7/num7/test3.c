#include<stdio.h>
#include<stdlib.h>
//�������int��32λ������m��n�Ķ����Ʊ��
//�ж��ٸ�λ(bit)��ͬ
void dif(int n, int m)
{
	int count = 0;
	for (int i = 0; i < 32; i++)
	{    //���ȥ�Ƚ�ÿһ��������λ
		if (((m >> i)&1)!=((n>>i)&1))
			count++;
	}
	printf("%d\n",count);
}
int main()
{
	dif(1999,2299);
	system("pause");
	return 0;
}