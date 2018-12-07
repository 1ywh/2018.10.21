#include<stdio.h>
#include<stdlib.h>
void inputData(int* a,int len){
	for (int i = 0; i < len - 1; i++){
		for (int j = 0; j < len - 1 - i; j++){
			if (a[j]>a[j + 1]){
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (int i = 0; i < len; i++){
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[9]={ 1, 34, 56, 74, 88, 9, 0, 33, 54 };
	int len = sizeof(a) / sizeof(a[0]);
	inputData(a,len);
	system("pause");
	return 0;
}