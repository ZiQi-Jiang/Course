#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   double r,d;
   cin >> r >> d;
   cout<<int(sqrt(r*r+d*d)-r)<<endl;
   return 0;
}
