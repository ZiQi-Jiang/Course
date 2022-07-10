#include<iostream>
#include<string>
using namespace std;
int main(){
    double a,b;
    while(cin>>a>>b){ 
        if(a>b){
            cout<<"Greater"<<endl;
            continue;
        }
        else if(a==b){
            cout<<"Equal"<<endl;
            continue;
        }
        cout<<"Less"<<endl;
    }
}