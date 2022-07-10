#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class A
{
    protected:
    int i;
    public:
    A(int i):i(i){cout<<"Call A:i="<<i<<endl;}
    void display(){cout<<"i="<<i<<endl;}

};
class A1:virtual public A
{
    protected:
    int j;
    public:
    A1(int i,int j):A(i),j(j){cout<<"Call A1:i="<<i<<endl;}

};
class A2:virtual public A
{
    protected :
    int k;
    A2(int i,int k):A(i),k(k){cout<<"Call A2:i="<<i<<endl;}

};
class A3:public A1, public A2
{
    public:
    A3(int i,int j,int k):A(i),A1(i,j),A2(i,k){cout<<"Call A3:i="<<i<<endl;}
    
    void disp()
    {
        display();
        cout<<"j="<<j<<endl;
        cout<<"k="<<k<<endl;
    }
};
int main()
{
   int i,j,k;
   cin >> i >> j >> k;
    A3 a(i,j,k);
    a.disp();
   return 0;
}
