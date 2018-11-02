#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//ĞÎÈç2+22+222+2222.....
int creatnum(int a, int n)
{
	if (a < 0 || a >= 10 || n <= 0)
		return 0;
	int num = 0;
	int i = 0;
	for (; i < n; i++)
	{
		num = num + a*pow(10, i);
	}
	return num;
}
int main(){
	int sum = 0, a = 2;
	for (int i = 1; i < 4; i++)
		sum = sum + creatnum(a, i);
	printf("%d\n", sum);
	system("pause");
	return 0;
}
