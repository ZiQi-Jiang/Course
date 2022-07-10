#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   int sum=0;
   int x;
   for(int i=0;i<5;i++)
   {
       
       cin >> x;
       sum +=x;
   }
   cout<<sum<<endl<<sum/5.0<<endl;
   return 0;
}
