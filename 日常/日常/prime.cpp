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
		cout << "��������"<< endl;
	}
	else{
		cout << "������" << endl;
	}
}
int main(){
	int a = 0;
	cout << "�����룺" << endl;
	cin >> a ;
	cout<<a;
	prime(a);
	system("pause");
	return 0;

}