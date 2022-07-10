#include <iostream>
using namespace std;
const double PI=3.14;
class Shape {
public:
    virtual double getArea()=0;
    virtual double getPerim()=0;
};

/*请在这里输入你的代码*/

void print(Shape* p)
{
    cout<<"Area:"<<p->getArea()<<endl;
    cout<<"Perimeter:"<<p->getPerim()<<endl;
}

class Rectangle:public Shape{
    protected:
        double l,w;
    public:
    Rectangle(double l, double w):l(l),w(w){}
    double getArea()
    {
        return l*w;
    }
    double getPerim(){ return 2*l+2*w;}
};

class Circle:public Shape{
    protected:
    double r;
    public:
    Circle(double r):r(r){}
    double getArea()
    {
        return PI*r*r;
    }
    double getPerim(){ return PI*r*2;}
};
int main(){
    double r,l,w;
    cin>>r;
    cin>>l>>w;
    Shape *p=NULL;
    p=new Circle(r);
    print(p);//输出圆面积与周长
    p=new Rectangle(l,w);
    print(p);//输出矩形面积与周长
    return 0;    
}