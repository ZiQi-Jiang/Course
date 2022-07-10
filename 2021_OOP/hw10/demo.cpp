#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   string str = "hello";
   for(auto & i : str){
       i+=1;
   }
   cout<<str;
   return 0;
}
