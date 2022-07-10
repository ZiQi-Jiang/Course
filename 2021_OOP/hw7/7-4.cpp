#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

class Animal{
    private:
    int num;
    string name;
    public:
    Animal(int num,string name):num(num),name(name){}
    int getnum(){ return num;}
    string getname(){return name;}
    virtual void eat()=0;
};
class Dog:public Animal{
    public:
    Dog(int num, string name):Animal(num,name){}
    void eat(){cout<<getnum()<<"号"<<getname()<<"啃骨头"<<endl;}


};
class Cat:public Animal{
    public:
    Cat(int num, string name):Animal(num,name){}
    void eat(){cout<<getnum()<<"号"<<getname()<<"吃小鱼"<<endl;}

    
};
int main()
{
    int num;
    string name;
    cin >> num >> name;
    // cout<<name;
    Animal* p;
    p = new Dog(num, name);
    p->eat();
    cin >> num >> name;
    p = new Cat(num, name);
    p->eat();
   
   return 0;
}
