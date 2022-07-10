/* 6-7 创建计算机 (10 分) */
/* distruct and disturct */
#include<iostream>
using namespace std;

class COMPUTER;
class RAM;
class CDROM;
class CPU;

class CPU{
    public:
    int rank,fre;
    float volt;
    CPU(int _r, int _f, float _v): rank(_r), fre(_f), volt(_v)
    {
        cout << "create a CPU!"<<endl;
    }
    CPU( CPU & a)
    {
        cout<<"create a CPU by copy!"<<endl;
        rank  = a.rank;
        fre = a.fre;
        volt = a.volt;
    }
    CPU()
    {
        cout<<"create a CPU!"<<endl;
        rank = 1;
        fre = 2;
        volt = 100;
    }
    ~CPU(){ cout << "desturct a CPU!"<< endl;}
    void showinfo()
    {
        cout<<"cpu parameter:"<<endl;
        cout<<"rank:"<<rank<<endl;
        cout<<"frequency:"<<fre<<endl;
        cout<<"voltage:"<<volt<<endl;
    }
};
class RAM{
    public:
    int volumn;
    RAM(int _v): volumn(_v){cout<<"create a RAM!"<<endl;}
    RAM(){volumn = 1; cout<<"create a RAM!"<<endl;}
    RAM( RAM & a)
    {
        cout<<"create a RAM by copy!"<<endl;
        volumn = a.volumn;
    }
    ~RAM(){ cout << "desturct a RAM!"<<endl;}
    void showinfo()
    {
        cout<<"ram parameter:"<<endl;
        cout<<"volumn:"<<volumn<<" GB"<<endl;
    }
    
};
class CDROM{
    public:
    int speed;
    CDROM(int _c):speed(_c){ cout << "create a CDROM!"<<endl;}
    CDROM(){ speed = 16; cout<<"create a CDROM!"<<endl;}
    CDROM(  CDROM & c)
    {
        cout<<"create a CDROM by copy!"<<endl;
        speed = c.speed;
    }
    ~CDROM(){ cout << "destruct a CDROM!"<<endl;}
    void showinfo()
    {
        cout<<"cdrom parameter:"<<endl;
        cout<<"speed:"<<speed<<endl;
    }
};

class COMPUTER
{
    public:
    CPU cpu;
    RAM ram;
    CDROM cdrom;
    COMPUTER(int rank, int fre, float volt, int volumn, int speed):
    cpu(rank, fre, volt), ram(volumn),cdrom(speed){ cout<<"create a COMPUTER with para!"<<endl;}
    COMPUTER(){cout<<"no para to create a COMPUTER!"<<endl;}
    COMPUTER(  COMPUTER & a):cpu(a.cpu),ram(a.ram),cdrom(a.cdrom)
    {
        
        cout<<"create a COMPUTER by copy!"<<endl;
    }
    ~COMPUTER()
    {
        cout<<"destruct a COMPUTER!"<<endl;
    }
    void showinfo()
    {
        cpu.showinfo();
        ram.showinfo();
        cdrom.showinfo();
    }
};

