#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

void foo(int x)
{
   cout<<x<<endl;
}

int main()
{
   const int i = 10;
   int x = i;
   x++;
   foo(i);
   
   
   return 0;
}
