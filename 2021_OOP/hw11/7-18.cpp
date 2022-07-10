#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{

    string str;
    cin >> str;
    sort(&str[0], &str[0] + str.size());
    cout << str<<endl;
    while (next_permutation(&str[0], &str[0] + str.size()))
    {
        cout << str << endl;
    }
}
