#include <iostream>
#include <iomanip>
using namespace std;

/* 你提交的代码将被嵌在这里 */
class TIME{
    public:
    int hour,minute,second;
    TIME(int h=0,int m=0,int s=0):hour(h),minute(m),second(s){}
    friend ostream & operator<<(ostream & out, const TIME & T)
    {
        printf("%02d:%02d:%02d",T.hour,T.minute,T.second);
        return out;
    }
    friend istream & operator>>(istream & in, TIME & T)
    {
        int x;
        char op;
        in >> x >> op;
        T.hour = x;
        in >> x >> op;
        T.minute = x;
        in >> x;
        T.second = x;
        return in;
    }
    bool operator>(const TIME & T)
    {
        if(hour > T.hour) return true;
        else if(hour == T.hour && minute > T.minute) return true;
        else if (hour == T.hour && minute ==T.minute && second > T.second) return true;
        return false;
    }
    bool operator>(int h)
    {
        TIME tmp(h);
        return *this>tmp;
    }
};
bool operator>(int h,TIME & T)
{
    TIME tmp(h);
    return tmp>T;
}