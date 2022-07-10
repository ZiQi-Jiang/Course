#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
using namespace std;

bool cmp(const string &s1, const string &s2)
{
    return (s1+s2)>(s2+s1);
}
int main()
{
    int N;
    vector<string> vct;
    while (cin >> N)
    {
        vct.clear();
        while (N--)
        {
            string str;
            cin >> str;
            vct.push_back(str);
        }
        sort(vct.begin(), vct.end(), cmp);
        for (auto it = vct.cbegin(); it != vct.cend(); it++)
            cout << *it;
        cout << endl;
    }

    return 0;
}
