#include<stdio.h>
#include<stdlib.h>
//×Ö·û·´ÏòÅÅĞò
int leng(char*str)
{

	/*if (*str != '\0')
	{
		str++; count = 1 + leng(str );
	}*/
	if (*str == '\0')
	{
		return 0;
	}
	else 	
		return 1 + leng(str+1);
	}
void reverse_string(char*str)
{
	if (*str)
	{
		int len = leng(str);
		char temp;
		temp= str[0];
		str[0] = str[len - 1];
		str[len - 1] = '\0';
		reverse_string(str + 1);
		str[len - 1] = temp;
	}
}
int main()
{
	char str[] = "asdfgh";
	reverse_string(str);
	printf("%s", str);	
	system("pause");
return 0;
}