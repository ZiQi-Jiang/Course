#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   string str;
   cin >> str;
   int count=0;
   int a = (str.length()+4)/4;
   for(int i=0;i<a;i++)
   {

    for(int j=0;j<a;j++)
     {
         if(i==0) cout<<str[j];
         else if(i==a-1) cout<<str[3*a-3-j];
         else if(j==0) cout<<str[4*a-4-i];
         else if(j==a-1) cout<<str[a-1+i];
         else cout<<" ";

     }
     cout<<endl;
   
   }

   return 0;
}
