#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   int h[10],num=0;
   int length;
   for(int i=0;i<10;i++)  cin >> h[i];
   cin >> length;
   length +=30;
   for(int i=0;i<10;i++)
   if(length>=h[i]) num++;
   cout<<num<<endl;
   return 0;
}
