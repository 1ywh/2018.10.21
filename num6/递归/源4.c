#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//斐波那契数
int f(int n)
{
   int f, f1 = 1, f2 = 1;
   for (int i = 3; i <= n; i++)
  {
	f = f1 + f2;
	f1 = f2;
	f2 = f;
   }
   return f;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("求第%d个斐波那契数： ", n);
	printf("%d", f(n));
	printf("\n");
	system("pause");
    return 0;
}