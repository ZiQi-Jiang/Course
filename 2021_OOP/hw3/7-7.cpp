/* 7-7 2017final游泳池过道造价 (20 分) */

#include<iostream>
using namespace std;
const double PI=3.14159;

int main()
{
    double r,a,b;
    cin >> r >> a >> b;
    cout<<20*(a*b-PI*r*r)<<endl;
}