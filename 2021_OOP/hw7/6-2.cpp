/*
基类的引用也可以实现多态 
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

class Vehicle
{
public:
    virtual void Run() { cout << "Vehicle run" << endl; }
    virtual void stop() { cout << "Vehicle stop" << endl; }
};

class Bicycle : public Vehicle
{
public:
    void Run() { cout << "Bicycle run" << endl; }
    void Stop() { cout << "Bicycle stop" << endl; }
};
class Motorcar : public Vehicle
{
    public:
    void Run(){cout<<"Motorcar run"<<endl;}

};

void run(Vehicle & ptr)
{
    ptr.Run();
}
