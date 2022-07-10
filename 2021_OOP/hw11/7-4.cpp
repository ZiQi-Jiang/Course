#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include<queue>
using namespace std;

int main()
{
   priority_queue<int,vector<int>, greater<int> > pq;
   int wpl=0;
   int n;
   cin >> n;
   while( n-- ){int x; cin >> x; pq.push(x);}
   while(pq.size()>=2)
   {
      int a = pq.top(); pq.pop();
      int b = pq.top(); pq.pop();
      int x = a + b; wpl+=x; pq.push(x);
   }
   cout<<wpl<<endl;

   return 0;
}
