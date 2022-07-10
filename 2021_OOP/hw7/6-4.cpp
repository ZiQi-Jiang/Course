#include <iostream>
using namespace std;

/* 你提交的代码将被嵌在这里 */

#include <cstdio>
class CAR
{
protected:
    double speed;

public:
    CAR(double speed) : speed(speed)
    {
       // printf("创建汽车(%g公里/小时)\n", speed);
       cout<<"创建汽车("<<speed<<"公里/小时)"<<endl;
    }
    virtual void Show() const
    {
       // printf("汽车: %g公里/小时\n", speed);
        cout<<"汽车: "<<speed<<"公里/小时"<<endl;
    }
};

class BUS : virtual public CAR
{
protected:
    int seat;

public:
    BUS(double speed, int seat) : CAR(speed), seat(seat)
    {
       // printf("创建客车(%d人)\n", seat);
         cout<<"创建客车("<<seat<<"人)"<<endl;
    }
    virtual void Show() const
    {
       // printf("客车: %g公里/小时, %d人\n", speed, seat);
        cout<<"客车: "<<speed<<"公里/小时, "<<seat<<"人"<<endl;
    }
};

class TRUCK : virtual public CAR
{
protected:
    double load;

public:
    TRUCK(double speed, double load) : CAR(speed), load(load)
    {
        // printf("创建货车(%g吨)\n",load);
        cout << "创建货车(" << load << "吨)" << endl;
    }
    virtual void Show() const
    {
        // printf("货车: %g公里/小时, %g吨\n",speed,load);
        cout << "货车: " << speed << "公里/小时, " << load << "吨" << endl;
    }
};

class VAN : public BUS, public TRUCK
{
public:
    VAN(double speed, int seat, double load) : CAR(speed), TRUCK(speed, load), BUS(speed, seat)
    {
        printf("创建客货两用车\n");
    }
    virtual void Show() const
    {
        //printf("客货两用车: %g公里/小时, %d人, %g吨\n",speed,seat,load);
        cout << "客货两用车: " << speed << "公里/小时, " << seat << "人, " << load << "吨" << endl;
    }
};
