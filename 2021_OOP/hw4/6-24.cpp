#include<iostream>
using namespace std;

class Client
{
    public:
    Client(){ ClientNum ++;}
    static char ServerName;
    static int ClientNum;
    static void changeServerName(char c){ ServerName = c;}
    static void show(){ cout<<"server name:"<<ServerName<<endl;
                       cout<<"num of clients:"<<ClientNum<<endl;}
    
};
int Client::ClientNum= 0;
 char Client::ServerName = 'A';
    