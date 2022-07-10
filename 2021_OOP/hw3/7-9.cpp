/* 7-9 游泳池改造 (30 分) */
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const double PI = 3.1415926;
int main()
{
   double r,w;
   cin >> r >> w;
   double p1 = 2*PI*( r  + w )*35;
   double p2 = PI*((r+w)*(r+w) - r*r)*20;
   cout <<p1<<endl;
   cout  << p2 << endl;
   return 0;
}
