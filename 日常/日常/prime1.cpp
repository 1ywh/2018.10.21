#include <iostream>
#include<cmath>
using namespace std;
struct student{
	int num;
};
bool judgeIsSushu(int n)
{
	int i;
	int s = int(sqrt(n));

	for (i = 2; i <= s; i++){
		if (n%i == 0)
			break;
	}

	if (i <= s)
		return false;
	else
		return true;
}

int main()
{
	int n;
	cout << "请输入一个大于1的整数：" << endl;
	cin >> n;
	cout << judgeIsSushu(n);
	system("pause");
	return 0;
}