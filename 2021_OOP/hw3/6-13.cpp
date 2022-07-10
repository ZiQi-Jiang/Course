/* 6-13 学生平均分计算 (10 分) */
#include<iostream>
#include<string>
using namespace std;
class Stud{
 static int sum,num;
 int id, grade;
  public:
 string name;
    Stud(int id, string name, int grade):id(id),name(name),grade(grade)
    {num++; sum+=grade;}
    void disp()
    {
    cout<<id<<","<<name<<","<<grade<<endl;
    }
    static int avg(){ return sum / num;}
    
};  