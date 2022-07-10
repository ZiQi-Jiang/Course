/* 7-3 定义基类Point和派生类Circle，求圆的周长. (10 分) */

#include <iostream>
#include<iomanip>
using namespace std;
//请编写你的代码
class Point
{
private:
    float x,y;
public:
    Point(float x_,float y_);
    ~Point();
};

Point::Point(float x_,float y_):x(x_),y(y_)
{
    cout<<"Point constructor called"<<endl;
}

class Circle: public Point
{
private:
    float r;
public:
    Circle(float x_, float y_, float r_);
    ~Circle();
    float getCircumference()
    {
        return 2*3.14*r;
    }
};

Circle::Circle(float x_, float y_, float r_):Point(x_,y_),r(r_){
    cout<<"Circle constructor called"<<endl;
}

Circle::~Circle()
{
    cout<<"Circle destructor called"<<endl;
}

Point::~Point()
{
    cout<<"Point destructor called"<<endl;
}

int main()
{
    float x,y,r;
    cin>>x>>y>>r;
    Circle c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getCircumference()<<endl;
    return 0;
}