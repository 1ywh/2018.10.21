#include<stdio.h>
#include<stdlib.h>
//�����ָ���������ð�ݷ�
//n������Ҫ����n-1�˱Ƚϣ�ÿһ����Ҫ����n-1-i�αȽ�
void sort(int arr[], int len)
{
	int i;
	int temp = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[] = { 5, 78, 3, 55, 78, 93 };
	printf("�������Ӵ�С����");
	int len = sizeof(arr) / sizeof (arr[0]);
	sort(arr, len);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}