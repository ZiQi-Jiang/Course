#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   double r1, r2, i1, i2;
   cin >> r1 >> i1 >> r2 >> i2;
   printf("(%g, %g)\n",r1+r2,i1+i2);
   printf("(%g, %g)\n",r1-r2,i1-i2);
   printf("(%g, %g)\n",r2,i2);
   return 0;
}
