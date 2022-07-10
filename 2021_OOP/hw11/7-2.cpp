#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
bool cmp(const string & a, const string & b){
    return a.length() < b.length();
}
int main()
{
   int n;
   string a[100];
   int k=0;
   while(++k)
   {
       cin >> n;
       if(n==0) break;
       for(int i=0;i<n;i++) cin >> a[i];
       sort(a,a+n,cmp);
       cout<<"SET: "<<k<<endl;
       for(int i=0;i<n;i++)
       cout<<a[i]<<endl;
   }
   return 0;
}
