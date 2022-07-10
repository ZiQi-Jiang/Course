#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

inline bool is_left(char a)
{
    return a=='('|| a== '{' || a=='[';
}
inline bool compact(char left,char right)
{
    if(left=='(') return right==')';
    if(left=='[') return right==']';
    if(left=='{') return right=='}';
}
void Solve()
{
    stack<char> stk;
        string in; cin >> in;
        for(int i=0;i<in.size();i++)
        {
            
        char tmp = in[i];
        if(is_left(tmp)) stk.push(tmp);
        else 
        {
            if(stk.empty()){cout<<"No"<<endl; return;}
            char right = tmp, left = stk.top();
            stk.pop();
            if(!compact(left,right))
            {cout<<"No"<<endl;return ;}
        }

        }
        if(stk.empty()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
}
int main()
{
    int T; cin >> T;
    while(T--)
    {
        Solve();
    }
    return 0;
}
