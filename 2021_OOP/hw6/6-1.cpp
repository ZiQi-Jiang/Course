
/* 6-1 狗的继承 (10 分) */
#include<iostream>
#include<string>
using namespace std;
class Animal{
    protected:int  age;
    public:
    Animal(int _age):age(_age){}
    int getAge(){ return age;}
};
class Dog: public Animal
{   
   string color;
   public:
   Dog(int _age, string _color):Animal(_age),color(_color){}
   void showInfor()
   {
    cout<<"age:"<<age<<endl;
    cout<<"color:"<<color<<endl;
    
   }
};