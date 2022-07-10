#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

template<class T>

class Number{
    T a;
    public:
    Number(T a):a(a){}
    Number(){}
    template<class T1>
    friend  const T1 & Max(const Number<T1> & t1, const Number<T1> & t2);
    template<class T1>
    friend  const T1 & Min(const Number<T1> & t1, const Number<T1> & t2);
    T Add(Number & t){return a+t.a;}
    T Sub(Number & t){return a-t.a;}
    T Mul(Number & t){return a*t.a;}
    T Div(Number & t){return a/t.a;}
    template<class T1>
    friend istream & operator>> (istream & i,  Number<T1> & t);
};
template<class T>
istream & operator>>(istream & i, Number<T> & t)
{
    i>>t.a;
    return i;
}

template<class T>
const T & Max(const Number<T> & t1, const Number<T> & t2)
{
    return t1.a>t2.a?t1.a:t2.a;
}

template<class T>
const T & Min(const Number<T> & t1, const Number<T> & t2)
{
    return t1.a>t2.a?t2.a:t1.a;
}

int main()
{
    Number<int> x,y;
    cin >> x >> y;
    cout<<Max(x,y)<<" ";
    cout<<Min(x,y)<<" ";
    cout<<x.Add(y)<<" ";
    cout<<x.Sub(y)<<" ";
    cout<<x.Mul(y)<<" ";
    cout<<x.Div(y)<<endl;
    Number<double> m,n;
    cin >> m >> n;
     cout<<Max(m,n)<<" ";
    cout<<Min(m,n)<<" ";
    cout<<m.Add(n)<<" ";
    cout<<m.Sub(n)<<" ";
    cout<<m.Mul(n)<<" ";
    cout<<m.Div(n)<<endl;

   
   return 0;
}
