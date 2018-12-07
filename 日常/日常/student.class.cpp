#include<iostream>
using namespace std;
//计算学生的平均成绩
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
	cout << "输入名字、语文成绩、数学成绩;" << endl;
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
		cout << "第"<<i+1<<"个学生的平均成绩"<<student[i].average()<< endl;
	}
}