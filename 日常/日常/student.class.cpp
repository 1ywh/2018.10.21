#include<iostream>
using namespace std;
//����ѧ����ƽ���ɼ�
class Student{
public:
	void input();
	float average();
private:
	char name[20];
	float math;
	float chinese;
};
void Student::input(){
	cout << "�������֡����ĳɼ�����ѧ�ɼ�;" << endl;
	cin >> name;
	cin >> chinese;
	cin >> math;
}
float Student::average(){

	float ave = (math+ chinese) / 2;
	return ave;
}
int main(){
	Student student[3];
	for (int i = 0; i < 3; i++)
	{
		student[i].input();
		cout << "��"<<i+1<<"��ѧ����ƽ���ɼ�"<<student[i].average()<< endl;
	}
}