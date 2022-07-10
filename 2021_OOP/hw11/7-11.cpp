#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    map<int, int> stu;
    string s;
    getline(cin,s);
    stringstream  ss(s);
    int x;
    while (ss>> x)
        stu[x]++;
    auto it = stu.cbegin();
    auto res = it;
    while(it!=stu.cend())
    {
        if(it->second > res->second) res = it;
        it++;
    }
    cout<<res->first<<endl;
}