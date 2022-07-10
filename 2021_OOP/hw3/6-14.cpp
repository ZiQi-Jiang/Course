/* 6-14 学生类的构造与析构 (10 分) */
#include<iostream>
#include<string>
using namespace std;
class Student
{
    private: 
    int id;
    string name;
    char gender;
    public:
    Student(int id,string name, char  gender):id(id),name(name),gender(gender)
    {
        cout<<"Constructor called."<<endl;
    }
    void display()
    {
        cout<<"num:"<<id<<endl;
        cout<<"name:"<<name<<endl;
        cout<<"sex:"<<gender<<endl;
        cout<<endl;
    }
    ~Student(){ cout<<"Destructor called."<<endl;}
};