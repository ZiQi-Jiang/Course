#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   int h1,h2,m1,m2,s1,s2;
   cin >> h1 >> m1 >> s1;
   cin >> h2 >> m2 >> s2;
   int h,m,s;
   s = s1+s2;
   m = m1+m2;
   h = h1+h2;
   while(s>=60)
   {
       s-=60;m++;
   }
   while(m>=24)
   {
       m-=24;h++;
   }
   //while(h>=24)h-=24;
   printf("%d %d %d",h,m,s);
   return 0;
}
