#include <stdio.h>
#include<stdlib.h>
//1--100������9,19,29...90,91...99
int main()
{
int count = 0, i;
 for (i = 1; i <= 100;i++)
{
if (i % 10 == 9)//�жϸ�λ����������Ϊ9
	count++;
if (i / 10 == 9)//�ж�ʮλ��
	count++;
}
printf("%d\n", count);
system("pause");
return 0;
}