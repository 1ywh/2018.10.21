#include <iostream>
using namespace std;
void prime(int count)
{
	int i = 0;
	for (i = 2; i < count; i++){
		if (count%i == 0){
			break;
		}
	}
	if (i<count){
		cout << "不是素数"<< endl;
	}
	else{
		cout << "是素数" << endl;
	}
}
int main(){
	int a = 0;
	cout << "请输入：" << endl;
	cin >> a ;
	cout<<a;
	prime(a);
	system("pause");
	return 0;

}