#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
const double PI = 3.1415926;
int main()
{
   double r;
   cin >> r;
   double p1 = 2*PI*( r  + 3 )*35;
   double p2 = PI*((r+3)*(r+3) - r*r)*20;
   cout << "Fencing Cost is $"<<p1<<endl;
   cout << "Concrete Cost is $" << p2 << endl;
   return 0;
}
