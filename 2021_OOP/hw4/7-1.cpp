#include<iostream>
using namespace std;
class Box
{
    private:
    float x;

   public:
    void seta(int x_)
    {
        x = x_; 
    }

    float getvolume()
    {
        return x*x*x;
    }
    float getarea()
    {
        return x*x*6;
    }
    void disp()
    {
        cout<< getvolume() 
        << " " << getarea()<<endl;
    }
};

int  main( ){

    float ab;
    cin>>ab;
    Box  obj;
    obj.seta( ab );
    obj.getvolume( );
    obj.getarea( );
    obj.disp( );
    return 0;
}