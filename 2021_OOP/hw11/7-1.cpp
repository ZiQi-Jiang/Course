#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    string a;
    cin >> a;
    cout << "year:" << a.substr(0, 4) << endl;
    cout << "department:" << a.substr(4, 2) << endl;
    cout << "class:" << a.substr(6, 2) << endl;

    return 0;
}
