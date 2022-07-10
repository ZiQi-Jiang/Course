/* 6-11 多重继承派生类构造函数 (10 分) */
#include<iostream>
using namespace std;
class Graduate
{
    public:
    Graduate(string name_, int age_, char sex_, string title_, double a, double b):name(name_),age(age_),sex(sex_),title(title_),score(a),wages(b){}
    void show()
    {
     cout<<"name:"<<name<<endl;
     cout<<"age:"<<age<<endl;
     cout<<"sex:"<<sex<<endl;
     cout<<"score:"<<score<<endl;
     cout<<"title:"<<title<<endl;
     cout<<"wages:"<<wages<<endl;
    }
    string name,title;
    double score,wages;
    char sex;
    int age;
};