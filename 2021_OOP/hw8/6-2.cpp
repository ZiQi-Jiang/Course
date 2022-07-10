#include <iostream>
#include <string>
using namespace std;

/* 请在这里填写答案 */
class Student{
    string name;
    static int num;
    int id;
    int grade;
    public:
    Student(){}
    friend ostream & operator<<(ostream & o, const Student & S) 
    {
        o<<S.id<<". "<<S.name<<" ";
        if(S.grade>=60) o<<"PASS";
        else o<<"FAIL";
        return o;
    }
    friend istream & operator>>(istream & i,  Student & S)
    {
        i >> S.name >> S.grade;
        S.id = Student::num++;
        return i;
    }
};

int Student::num = 1;
