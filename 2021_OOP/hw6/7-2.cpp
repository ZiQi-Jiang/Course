/* 7-2 动物世界 (15 分) */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

enum COLOR{ WHITE, RED, BROWN, BLACK, KHAKI };

class Mammal
{
    public:
        //constructors
        Mammal();
        Mammal(int age);
        Mammal(int age, int weight):itsAge(age),itsWeight(weight){}
        ~Mammal();

        //accessors
        int GetAge() const;
        void SetAge(int);
        int GetWeight() const;
        void SetWeight(int);

        //Other methods    
        void Speak() const;
        void Sleep() const;        
    protected:
        int itsAge;
        int itsWeight;
};
Mammal::Mammal(){};
Mammal::~Mammal(){};
Mammal::Mammal(int age):itsAge(age){}
int Mammal::GetAge() const{return itsAge;}
int Mammal::GetWeight() const{ return itsWeight;}
void Mammal::SetAge(int a){itsAge = a;}
void Mammal::SetWeight(int w){itsWeight = w;}

void Mammal::Speak()const { cout<<"Mammal is speaking..."<<endl;}
void Mammal::Sleep() const{cout<<"Mammal is sleeping..."<<endl;}

class Dog: public Mammal
{
    protected:
    COLOR itsColor;
    public:
    Dog(){}
    Dog(int age):Mammal(age){}
    Dog(int age, int weight):Mammal(age, weight){}
    Dog(int age, COLOR color):Mammal(age),itsColor(color){}
    Dog(int age, int weight, COLOR color):Mammal(age, weight),itsColor(color){}
    COLOR GetColor(){ return itsColor;}
    void SetColor(COLOR color){itsColor = color;}
    void WagTail(){cout<<"The dog is wagging its tail..."<<endl;}


};

int main()
{
    Dog Fido;
    Dog Rover(5);
    Dog Buster(6, 8);
    Dog Yorkie(3, RED);
    Dog Dobbie(4, 20, KHAKI);
    Fido.Speak();
    Rover.WagTail();
    cout << "Yorkie is " << Yorkie.GetAge() << " years old." << endl;
    cout << "Dobbie weighs " << Dobbie.GetWeight() << " pounds." << endl;   
    return 0;
}
