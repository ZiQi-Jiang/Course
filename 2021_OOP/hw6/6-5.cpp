/* 6-5 车的继承 (10 分) */
#include<iostream>
using namespace std;
class vehicle
{
    public:
    double speed,weight;
    vehicle(double Speed, double Weight):speed(Speed), weight(Weight){}
};
class bicycle: virtual public vehicle
{
    public:
    double height;
    bicycle(double s, double w, double h):vehicle(s,w),height(h){}
};
class motorcycle: virtual public vehicle
{
    public:
    int seatNum;
    motorcycle(double s, double w, int seat):vehicle(s,w),seatNum(seat){}
    
};
class Motorcar: public bicycle, public motorcycle
{
public:
    Motorcar(double s,double w, double h, int seat):vehicle(s,w),bicycle(s,w,h),motorcycle(s,w,seat){}
};