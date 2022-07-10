#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

void Print(int v)
{
    cout<<" "<<v;
}
int main()
{
    vector<int> vct;
    int x;
    while (cin >> x)
        vct.push_back(x);
    sort(vct.begin(), vct.end());
   cout<<"从标准设备读入数据，直到输入是非整型数据为止"<<endl;
  for_each(vct.cbegin(),vct.cend(),Print);
    return 0;
}
