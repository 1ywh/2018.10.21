#include <stdio.h>
#include<stdlib.h>
//1--100个数中9,19,29...90,91...99
int main()
{
int count = 0, i;
 for (i = 1; i <= 100;i++)
{
if (i % 10 == 9)//判断个位数，求余数为9
	count++;
if (i / 10 == 9)//判断十位数
	count++;
}
printf("%d\n", count);
system("pause");
return 0;
}