#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include<map>
using namespace std;

typedef map<string,int> MYMAP;
int main()
{

   MYMAP mp;
   int T,N;
   cin >> T;  
   while(T--)
   {
       mp.clear();
       cin >> N;
       while(N--)
       {
           string str;
           cin >> str;
           mp[str]++;
       }
   auto it = mp.cbegin();
   while(it!=mp.cend())
   {
       cout<<it->first<<" "<<it->second<<endl;
       it++;
   }
   }
   return 0;
}
