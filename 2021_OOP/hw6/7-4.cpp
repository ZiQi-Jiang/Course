#include <iostream>
#include<iomanip>
using namespace std;
const double PI=3.14;
//请编写你的代码
class Dot
{
    private:
    float x,y;
    public:
    Dot(float _x, float _y):x(_x),y(_y)
    {cout<<"Dot constructor called"<<endl;}
    ~Dot(){cout<<"Dot destructor called"<<endl;}

};
class Cir:public Dot{
    private:
    float r;
    public:
    float getArea(){ return PI*r*r;}
    Cir(float x, float y, float r):Dot(x,y),r(r)
    {cout<<"Cir constructor called"<<endl;}
    ~Cir(){cout<<"Cir destructor called"<<endl;}
};
int main(){
    float x,y,r;
    cin>>x>>y>>r;
    Cir c(x,y,r);
    cout<<fixed<<setprecision(2)<<c.getArea()<<endl;
    return 0;
}
