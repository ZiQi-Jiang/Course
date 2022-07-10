#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   float a,b;
   cin >> a >> b;
   if(a<=0 || a>=50) a = 1;
   if(b<=0 || b>=50) b = 1;
   printf("%g",2*(a+b));
   return 0;
}

