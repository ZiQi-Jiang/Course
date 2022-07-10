#include<iostream>
using namespace std;

int Max(int* a)
{
    int res = a[0];
    for(int i=0;i<5;i++)
      if(res < a[i] ) res = a[i];
    return res;
}
float Max(float* a)
{
    float res = a[0];
    for(int i=0;i<5;i++)
      if(res < a[i] ) res = a[i];
    return res;
}

long Max(long* a)
{
    long res = a[0];
    for(int i=0;i<5;i++)
      if(res < a[i] ) res = a[i];
    return res;
}

int main()
{
    int a[5];
    float b[5];
    long c[5];

    
   for(int i=0;i<5;i++)  cin>>a[i];
   cout<<Max(a)<<endl;
for(int i=0;i<5;i++)  cin>>b[i];
   printf("%f\n",Max(b));
     for(int i=0;i<5;i++)  cin>>c[i];
   cout<<Max(c)<<endl;
    
}