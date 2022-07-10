#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
const double PI=3.1415;
class Shape{
    public:
    virtual void printArea()=0;

};

class Circle: public Shape{
    double r;
    public:
    Circle(double r):r(r){}
    void printArea()
    {
        printf("%.2f\n",r*r*PI);
    }

};
class Rectangle:public Shape{
    double l,w;
    public:
    Rectangle(double l, double w):l(l),w(w){}
    void printArea()
    {
        printf("%.2f\n", l*w);
    }
};

class Triangle:public Shape{
    double a,b;
    public:
    Triangle(double a,double b):a(a),b(b){}
    void printArea()
    {
        printf("%.2f\n",0.5*a*b);
    }
};
int main()
{
   double a,b;
   Shape* p;
   cin >> a;
   p = new Circle(a);
   p->printArea();
   cin >> a >> b; p = new Rectangle(a,b); p->printArea();
   cin >> a >> b; p = new Triangle(a,b);  p->printArea();
   return 0;
}
