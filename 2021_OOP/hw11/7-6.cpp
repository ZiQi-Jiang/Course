#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include<list>
using namespace std;

int main()
{
   list<string> lst;
   int n;
   string name;
   string op;
   cin >> n;
   while(n--)
   {
       cin >> op;
      if(op=="in")
      {
          cin >> name;
          lst.push_back(name);
      }
      else if(op=="out") lst.pop_front();
      else {
          if(lst.empty()) cout<<"NULL"<<endl;
          else cout<<lst.front()<<endl;
      }
   }
   return 0;
}
