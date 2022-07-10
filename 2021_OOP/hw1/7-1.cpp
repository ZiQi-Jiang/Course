//getline 处理回车，也就是最后的回车不在缓冲区内，而cin遇见回车停止，回车仍在缓冲区

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
const int MAX_N = 10;
typedef class{
	public:
    string name;
    double price;
} Student;
using namespace std;
int main()
{
    int n;
    string ins;
    Student s[MAX_N];
    s[0].name="fadsf";
    cin >> n;
    getchar();
   // cin >> ins;
    for(int i=0;i<n;i++)
    {
         getline(cin,s[i].name);
         //<s[i].name;
		 cin >> s[i].price;
        getchar();
    }
   //out << s[0].name << s[0].price<<endl;
    int index=0;
    for(int i=0;i<n;i++)
        if(s[i].price > s[index].price) index = i;
    cout << "highest price: "<<s[index].price<<", "<<s[index].name<<endl;
    return 0;         
}