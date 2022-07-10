
/* 7-6 宿舍谁最高？ (20 分) */
/* 注意：000001应该是int型，不是string！！！ */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
class Student
{
    public:
    int ID;string name;
    int height,weight;
    public:
    Student(){};
    Student(int  a,string b,int c, int d):ID(a),name(b),height(c),weight(d){}
    void get_value()
    {
        cin >> ID >> name >> height >> weight;
    }
    void display()
    {
        printf("%06d ",ID);
        cout<<name<<" "<<height<<" "<<weight<<endl;
    }
   
} s[100000];
bool cmp(const Student & s1, const Student & s2)
{
    if(s1.ID < s2.ID ) return true;
    else if(s1.ID == s2.ID && s1.height > s2.height) return true;
    return false;
}
int main()
{
    int i = 0;
    int n;
  
   cin >> n;
   for(int i=0;i<n;i++)
   s[i].get_value();
   sort(s,s+n,cmp);
   int  oldID,newID;
   s[0].display();
   oldID = s[0].ID;
   for(int i=1;i<n;i++)
   if(s[i].ID!=oldID)
   {
       s[i].display();
       oldID = s[i].ID;
   }

   return 0;
}
