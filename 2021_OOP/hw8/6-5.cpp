#include<iostream>
using namespace std;

/* 请在这里填写答案 */
class Point
{
    double a, b;
public:
    Point(double a1=0, double b1=0)
    {
        a = a1;
        b = b1;
    }
    Point operator+(const Point& p)
    {
        return Point(a + p.a, b + p.b);
    }
    Point operator-(const Point& p)
    {
        return Point(a - p.a, b - p.b);
    }
    Point operator+=(const Point &p)
    {
        //return Point(a + p.a, b + p.b);不能写成像重载+运算符一样，写成这样返回的是a+=b的a
        a += p.a;
        b += p.b;
        return *this;
    }
    bool operator==(Point& p)     //重载==运算符是这样重载的 用bool函数返回是或否
    {
        if (a == p.a && b == p.b)
            return true;
        else
            return false;
    }
    friend ostream& operator<<(ostream &out,Point &p)    //注意只能重载为非成员函数(即不是成员函数，是友元函数或是普通函数即非成员非友元函数)的运算符有>>,<< 
    {
        out << p.a << "," << p.b;
        return out;
    }
};