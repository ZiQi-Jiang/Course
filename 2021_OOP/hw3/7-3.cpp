/* 
乒乓球的年度考核 
*/

//胜利的局数和场数不同,B应该把每场局数加起来
#include<iostream>
using namespace std;
class Group
{
    public:
    string name;
    public:
    virtual void display() = 0;
};
class GroupA: public Group
{
    public:
    int grade = 0;
    void display()
    {
        cout << name << " A ";
    }
};
class GroupB: public Group
{
    public:
    int grade = 0;
    void display()
    {
        cout << name << " B ";
    }
};
int main()
{
    Group* ptr[30];
    int index = 0;
    //bool first_line = true;
    string a;
    while( 1 )
    {
        cin >> a;
        if(index) cout<<endl;
        if(a == "0") break;
        else if(a == "A") ptr[index] = new GroupA;
        else if(a == "B") ptr[index] = new GroupB;
        cin >> ptr[index]->name;
        ptr[index]->display();
        if(a == "A") 
        {
            int a,b;
            cin >> a >> b;
            cout <<2*a - b ;
        }
        else
        {
            
            getline(cin,a);
            int grade = 0;
            for(int i=1;i<=(int )a.length();i+=4)
             grade += a[i]-a[i+2];
            
            cout << grade;
            
        }
       
        index++;
    }
    //for(int i=0;i<index;i++)
    //delete ptr[index];
}
