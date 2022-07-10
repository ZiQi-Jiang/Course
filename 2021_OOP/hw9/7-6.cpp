#include<bits/stdc++.h>
using namespace std;
#define PI "314159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"

int main()
{
    int n,x,i,j;
    cin>>n;
    string s(PI);
    int flag=0;
    for(i=0;i<n;i++){
        string s1=s.substr(flag,i*2+1);
        cout<< setw((n*2-1)/2+1+i)<<s1<<endl;
        flag+=i*2+1;
    }
    return 0;
}
