#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <string.h>//�۰����
int main()
{
	int mid = 0;//ȫ�ֱ���
	int  a[] = { 1, 2, 3, 4, 5 };//�ȶ�������,��ֵ,��ֵ,Ҫ�ҵ���
	int left = 0;
	int right = sizeof(a) / sizeof(a[0]) - 1;//[0,4]
	int to_find = 0;
	printf("������Ҫ�ҵ�����");
	scanf("%d", &to_find);
	while (left <= right)//����������ֵС����ֵ
	{
		mid = (left + right) / 2;
		if (to_find <a[mid])
		{
			right = mid - 1; //[0,mid-1]
		}
		else if (to_find>a[mid])
		{
			left = mid + 1;//[mid-1,right]
		}
		else if (to_find == a[mid])
		{
			printf("�ҵ����±�Ϊ��%d\n", mid);
			break;
		}
	}
		system("pause");
		return 0;
	}

