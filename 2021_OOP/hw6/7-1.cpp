/* 7-1 日程安排（多重继承+重载） (40 分) */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Date{
    protected:
    int year, month, day;
};
class Time{
    protected:
    int hour, minute,second;
};

class Schedule: public Time, public Date{
    protected:
    int ID;
    public:
    void set_ID(int n){ ID = n; }
    void get_Sche()
    {
        scanf("%d/%d/%d %d:%d:%d", & year, & month, &day, &hour, &minute, & second);
    }
    void print(){
        printf("The urgent schedule is No.%d: %d/%d/%d %d:%d:%d\n",ID,year,month,day,hour,minute,second);
    }
    bool operator < (const Schedule & s2);
};
bool Schedule::operator<(const Schedule & s2)
{
    if(year < s2.year) return 1;
    if(year > s2.year) return 0;
    if(month < s2.month) return 1;
    if(month > s2.month) return 0;
    if(day < s2.day) return 1;
    if(day > s2.day) return 0;
    if(hour < s2.hour) return 1;
    if(hour > s2.hour) return 0;
    if(minute < s2.minute) return 1;
    if(minute > s2.minute) return 0;
    if(second < s2.second) return 1;
    if(second > s2.second) return 0;
    return 0;
    

}

int main()
{
   int num;
   Schedule result;
   int i = 0;
   while(1)
   {
       scanf("%d", &num);
       if(num == 0) break;
       Schedule temp;
       temp.set_ID(num);
       temp.get_Sche();
       if(i == 0) result = temp;
       else if(temp < result) result = temp;
       i++;
   }
   result.print();
   return 0;
}
