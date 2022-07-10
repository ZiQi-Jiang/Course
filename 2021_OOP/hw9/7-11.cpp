#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    cout<<s<<endl;
    //cout<<s<<endl;
    int a[10000],i=0,j;
    stringstream stream(s);
    while(stream>>a[i++]);
    
    /**/
    cout<<a[0];//是这个意思叭
    for(j=1;j<i-1;j++){//直接输出两遍S不好喵
        cout<<" "<<a[j];//嘤
    }
    cout<<endl;
    /**/
    
    sort(a,a+i-1);
    cout<<a[0];
    for(j=1;j<i-1;j++){
        cout<<" "<<a[j];
    }
    return 0;
}
