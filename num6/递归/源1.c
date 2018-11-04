#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//µÝ¹éÇónµÄ½×³Ë
int  fac(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else  return n*fac(n - 1); 
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d!=%d",n,fac(n));
    system("pause");
    return 0;
}