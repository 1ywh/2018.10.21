#include <stdio.h>
#include<stdlib.h>
//1--100������9,19,29...90,91...99
int nine_count(int x)
{
	int count = 0;
	if (x / 10 == 9)
		count++;
	if (x%10 == 9)
		count++;
	return count;
}
int main()
{
	int i,count = 0;//���ø���Ϊ0�������ȥ�ж�,��ʱҪ�����жϺ���
	for (i = 1; i <=100; i++)
	{
		count += nine_count(i);
	}//����ǵĻ���������1
	printf("9�ĸ�����%d\n", count);
system("pause");
return 0;
}