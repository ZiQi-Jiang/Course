//类成员函数编写
//类的静态成员
//cout设置小数点后2位
//属性初始化

#include<iostream>
#include<iomanip>
using namespace std;
 class Student{
	public:
	char num[6];
	char name[8];
	double score[3];
	double sum_socre = 0;
	
	void Print(){
		cout << num <<" "<<name << " "<<score[0]<<" "<<score[1]<<" " \
		     <<score[2]<<endl;
	}
	
	static double all_sum;
};

double Student::all_sum=0;
int main()
{
    
	Student stu[10];
	int index = 0;
	for(int i=0;i<10;i++)
	{
		cin >> stu[i].num >> stu[i].name;
		
		for(int j=0;j<3;j++)
		{
		  cin >> stu[i].score[j];
		  stu[i].sum_socre +=stu[i].score[j];
		}
		Student::all_sum += stu[i].sum_socre;
	}
	cout <<fixed<<setprecision(2)<< Student::all_sum /30 <<endl;
	
	for(int i=0;i<10;i++)
	  if(stu[i].sum_socre > stu[index].sum_socre)  index = i;
	stu[index].Print();
	return 0;
}