/* 6-15 鸭子也是鸟 (10 分) */
class Bird
{
    public:
    void speak(){ cout<<"Jiu-Jiu-Jiu"<<endl;}
};

class Duck: public Bird
{
    string name;
    public:
    Duck(string name):name(name){};
    void printName(){ cout<<"Dird Name:"<<name<<endl;}
    
};