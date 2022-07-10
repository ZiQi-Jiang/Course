/* 6-19 时间的比较(*) (20 分) */

#include <iostream>
#include <iomanip>
using namespace std;

/* 你提交的代码将被嵌在这里 */
class TIME{
    public:
    int h,m,s;
    public:
    TIME(int _h=0, int _m=0, int _s = 0):h(_h), m(_m), s(_s){}
    
    bool operator > (const TIME & t2);
    friend ostream &  operator << (ostream & os, const TIME & c);
    friend istream & operator >>(istream & is,  TIME & c);


};
bool TIME::operator>(const TIME & t2)
{
    int a = this->h*60*60 + this->m*60 + this->s;
    int b = t2.h*60*60 + t2.m*60 + t2.s;
    return a > b;
}
bool operator >(const int h, TIME & b)
{
        int a = b.h*3600+b.m*60+b.s;
        return h>b.h;
}
ostream & operator<< (ostream & os, const TIME & c)
{
    cout.width(2);
    cout.fill('0');
    
    os <<setfill('0')<<setw(2)<<c.h<<":";

    os<<setfill('0')<<setw(2)<<c.m;
    
    os<<":"<<setfill('0')<<setw(2)<<c.s;
    return os; 
}
istream & operator >> (istream & is,  TIME & c)
{
    string s;
    char op;
    is >> c.h>>op>>c.m>>op>>c.s;
    return is;
    /*
    int pos = s.find_first_of(":",0);
    string tmp = s.substr(0,pos);
    c.h = atoi(tmp.c_str());
    s = s.substr(pos+1);
    pos = s.find_first_of(":",pos+1);
    tmp = s.substr(0,pos);
    c.m = atoi(tmp.c_str());
    
    s = s.substr(pos+1);
    c.s = atoi(s.c_str());
    */
    return is;
}