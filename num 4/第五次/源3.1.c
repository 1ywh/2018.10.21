#include<stdio.h>
#include<stdlib.h>
//2+22+222+...
int main()
{
	int sum = 0,a=2 ;
	for (int i = 1; i <=4; i++)
	{
		sum = sum + a;
		a = 2+a * 10;
	}
	printf("%d",sum);
    system("pause");
    return 0;
}