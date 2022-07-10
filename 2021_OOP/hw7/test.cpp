#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

class Base{
    public:
    static int num;
    Base(){ }
};
class Derived:public Base{
    public:
    Derived(){ num+=2;}
};