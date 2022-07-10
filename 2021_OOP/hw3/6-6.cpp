/* 6-6 创建CPU (10 分) */

#include<iostream>
#include<string>
using namespace std;

enum CPU_Rank{P1 = 1,P2,P3,P4,P5,P6,P7};
class CPU
{
    public:
    CPU_Rank p;
    int  f;
    float v;
    CPU(){ cout<<"create a CPU!"<<endl;p = P1; v= 100; f = 2;}
    CPU(CPU_Rank _p, int _f, float  _v): p(_p), f(_f), v(_v){
        cout<<"create a CPU!"<<endl;
    }
    CPU(const CPU & a )
    {
        cout<<"copy create a CPU!"<<endl;
        p = a.p;
        f = a.f;
        v = a.v;
    }
    ~CPU()
    {
        cout<<"destruct a CPU!"<<endl;
    }
    void showinfo()
    {
        cout << "rank:"<<p<<endl;
        cout<<"frequency:"<<f<<endl;
        cout<<"voltage:"<<v<<endl;
        
    }
};
