#include <stdio.h>
#include<stdlib.h>
//1--100个数中9,19,29...90,91...99
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
	int i,count = 0;//先让个数为0，在逐个去判断,这时要调用判断函数
	for (i = 1; i <=100; i++)
	{
		count += nine_count(i);
	}//如果是的话给个数加1
	printf("9的个数：%d\n", count);
system("pause");
return 0;
}