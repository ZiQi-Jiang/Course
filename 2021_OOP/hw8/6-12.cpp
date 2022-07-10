#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
class COMPLEX
{
public:
    double real, image;
    COMPLEX() { real = image = 0; }
    COMPLEX(double r) : real(r) {}
    COMPLEX(double r, double i) : real(r), image(i) {}
    friend ostream &operator<<(ostream &out, const COMPLEX &C)
    {
      
        out << C.real;
        if (C.image >= 0)
            out << "+" << C.image << "i";
        else
            out << C.image << "i";
        return out;
    }
    friend istream &operator>>(istream &in, COMPLEX &C)
    {
        char op;
        char i;
        in >> C.real >> op >> C.image >> i;
        if (op == '-')
            C.image = -C.image;
        return in;
    }
    COMPLEX operator+(const COMPLEX &C)
    {
        return COMPLEX(real + C.real, image + C.image);
    }
    friend COMPLEX operator+(double r, COMPLEX & C)
    {
        cout<<r<<endl;
        return COMPLEX(C.real,C.image);
    }
    COMPLEX &operator=(const COMPLEX &C)
    {
        real = C.real;
        image = C.image;
        return *this;
    }
};
