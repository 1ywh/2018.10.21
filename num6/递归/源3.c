#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
// µœ÷n^k”√µ›πÈ
int pow(int x,int y)
{
	if (y == 1)
	{
		return x;
	}
	else 	return x*pow(x, y-1);
}
int main()
{
	int n, k;
	scanf("%d %d",&n,&k);
	printf("%d^%d=%d",n,k,pow(n,k));	
	system("pause");
return 0;
}