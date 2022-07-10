#include <iostream>
#include<iomanip>
using namespace std;
 
int Max(int a,int b,int c,int d,int e){
    if(b > a) a = b;
    if(c > a) a = c;
    if(d > a) a = d;
    if(e > a) a = e;
    return a;
}
 
double  Max(double a,double b,double c,double d,double e){
    if(b > a) a = b;
    if(c > a) a = c;
    if(d > a) a = d;
    if(e > a) a = e;
    return a;
}
 
long long int Max(long long int a,long long int b,long long int c,long long int d,long long int e){
    if(b > a) a = b;
    if(c > a) a = c;
    if(d > a) a = d;
    if(e > a) a = e;
    return a;
}
 
int main()
{
    int a,b,c,d,e;
    double  a1,b1,c1,d1,e1;
    long long int a2,b2,c2,d2,e2;
    cin>>a>>b>>c>>d>>e;
    cin>>a1>>b1>>c1>>d1>>e1;
    cin>>a2>>b2>>c2>>d2>>e2;
    int m;
    m = Max(a,b,c,d,e);
    printf("%d\n",m);
    double n;
    n = Max(a1,b1,c1,d1,e1);
    cout.precision( 10); 
    cout<<n<<endl;
    long long int p;
    p = Max(a2,b2,c2,d2,e2);
    cout<<p<<endl;
    return 0;
}

