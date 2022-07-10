#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <sstream>

using namespace std;
class Array
{
public:
    vector<int> a;

public:
    Array() {}
    Array(vector<int> a) : a(a) {}
    Array operator+(const Array &A);
    friend istream &operator>>(istream &in, Array &a);
    friend ostream &operator<<(ostream &out, Array &a);
};

Array Array::operator+(const Array &A)
{
    vector<int> res;
    for (int i = 0; i < a.size(); i++)
    {
        int x = a[i] + A.a[i];
        res.push_back(x);
    }
    return Array(res);
}
istream &operator>>(istream &in, Array &A)
{
    string str;
    int x;
    getline(in, str);
    stringstream ss(str);
    while (ss >> x)
    {
        A.a.push_back(x);
    }
    return in;
}
ostream &operator<<(ostream &out, Array &A)
{
    for (int i = 1; i <= A.a.size(); i++)
    {
        out <<setw(3) <<A.a[i - 1];
        if (i % 3 == 0)
            out << endl;
        
            
    }
    return out;
}