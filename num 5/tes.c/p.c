#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Сд��ĸ=��д��ĸ+32
int main()
{
	char a = 0;
	printf("����:");
	scanf("%c", &a);
	if (a <= 'z'&&a >= 'a')//�����Сд�����д
		printf("%c\n", a - 32);
	else if (a <= 'Z'&&a >= 'A')
	{
		printf("%c\n", a + 32); //�Ǵ�д�����Сд
	}
	system("pause");
	return 0;
}
