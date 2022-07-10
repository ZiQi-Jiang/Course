/* R6-2 求Box的体积（类的定义与使用） (10 分) */

#include<iostream>
using namespace std;

class Box{
    double x,y,h;
    public:
    void get_value(){ cin >> x >> y >> h;}
    void display(){ cout<<x*y*h<<endl;}
};