#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    set<int> f, s, jiao;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        f.insert(a);
    }
    for (int j = 0; j < m; j++)
    {
        int b;
        cin >> b;
        s.insert(b);
    }
    for (set<int>::iterator it = f.begin(); it != f.end(); it++) //求交
    {
        if (s.find(*it) != s.end())
            jiao.insert(*it);
    }
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) //求并
    {
        f.insert(*it);
    }
    //输出
    cout << jiao.size();
    for (set<int>::iterator it = jiao.begin(); it != jiao.end(); it++) //求并
    {
        printf(" %d", *it);
    }
    cout << endl;
    cout << f.size();
    for (set<int>::iterator it = f.begin(); it != f.end(); it++) //求并
    {
        printf(" %d", *it);
    }
    return 0;
}
