#include<iostream>
using namespace std;
//针对有序数组折半查找 
void show(int* a, int length, int find){
	for (int i = 0; i < length; i++)
	{
		cout << a[i] << endl;
	}
	int left = 0;
	int mid;
	int right = length - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (find < a[mid])
		{
			right = mid - 1;
		}
		else if (find>a[mid])
		{

			left = mid + 1;
		}
		else 
		{
			cout << "找到了,下标为" << mid<<endl;
			break;
		}
		
	}
	if (find != a[mid])
	{
		cout << "没找到" << endl;		
	}
}
int main()
{
	int a[]= {1,2,3,4,5};
	show(a,5,2);
	system("pause");
	return 0;

}