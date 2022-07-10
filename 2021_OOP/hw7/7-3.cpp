#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
const double PI=3.14159;
class Shape{

    public:
    static double sumArea;
    virtual void Area()=0;

};
double Shape::sumArea=0;

class Circle: public Shape{
    double r;
    public:
    Circle(double r):r(r){}
    void Area()
    {
        sumArea +=PI*r*r;
    }

};
class Rectangle:public Shape{
    double l,w;
    public:
    Rectangle(double l, double w):l(l),w(w){}
    void Area()
    {
        sumArea += l*w;
    }
};

class Triangle:public Shape{
    double a,b;
    public:
    Triangle(double a,double b):a(a),b(b){}
    void Area()
    {
        sumArea += a*b*0.5;
    }
};
class Square:public Shape{
    double a;
    public:
    Square(double a):a(a){}
    void Area(){ sumArea += a*a;}
};
class Trapezoid:public Shape{
    double a,b,h;
    public:
    Trapezoid(double a,double b, double h):a(a),b(b),h(h){}
    void Area(){ sumArea+=(a+b)*h*0.5;}

};

int main()
{
   double a,b,h;
   Shape* p;
   cin >> a;
   p = new Circle(a);
   p->Area();
   cin >> a; p = new Square(a); p->Area();
   cin >> a >> b; p = new Rectangle(a,b); p->Area();
   cin >> a >> b >> h; p = new Trapezoid(a,b,h);p->Area();
   cin >> a >> b; p = new Triangle(a,b);  p->Area();
   printf("%.3f",Square::Shape::sumArea);
   return 0;
}
