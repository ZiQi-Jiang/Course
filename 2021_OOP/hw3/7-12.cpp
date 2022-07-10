/* 7-12 （组合类）一定平面二维点类Point，线段类Line是由两个Point点组成的组合类 (30 分) */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Point
{
    public:
    int x,y;
    public:
    Point(int x_, int y_):x(x_), y(y_)
    {
        printf("create Point:P(%d,%d)\n",x,y);
    }
    void print()
    {
         printf("P(%d,%d)",x,y);
    }

};
class Line{
    Point start,end;
    public:
    Line(Point s, Point e):start(s), end(e)
    {
        cout<<"Create a new Line:"<<endl;
    }
    Point & GetPstart(){ return start;}
    Point & GetPend(){ return end;}
    int GetLen(){ 
        int x_2 = (start.x - end.x)*(start.x - end.x);
        int y_2 = (start.y - end.y)*(start.y - end.y);
        return sqrt(x_2 + y_2);
    }

};
int main() {
int x1,y1,x2,y2; cin>>x1>>y1;
cin>>x2>>y2; Point myp1(x1,y1),myp2(x2,y2); //建立Point类的对象 
Line L1(myp1,myp2); //建立Line类的对象
 cout<<"Line start Point is:";
  L1.GetPstart().print(); 
  cout<<endl; 
  cout<<"Line end Point is:";
   L1.GetPend().print();
    cout<<endl; 
    cout<<"Length of Line is:"<<L1.GetLen()<<endl;

}