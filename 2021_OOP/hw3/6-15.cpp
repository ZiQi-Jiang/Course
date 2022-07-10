/* 6-15 定义点类 (10 分) */
#include<iostream>
using namespace std;
class Point{
   int x,y;
    public:
   void setXY(int x_, int y_){ x = x_; y = y_;}
    int getX(){ return x;}
    int getY(){ return y;}
};