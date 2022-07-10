/* 6-3 客货两用车(*) (20 分) */
class CAR{
    protected:
    double speed;
    public:
    CAR(double a):speed(a){
        cout<<"创建汽车("<<speed<<"公里/小时)"<<endl;
    }
    virtual void Show()const{
        cout<<"汽车: "<<speed<<"公里/小时"<<endl;
    }
};
class BUS:virtual public CAR{
    protected:
    int seat;
    public:
    BUS(double a,int b):CAR(a),seat(b){
        cout<<"创建客车("<<seat<<"人)"<<endl;
    }
    void Show()const{
        cout<<"客车: "<<speed<<"公里/小时, "<<seat<<"人"<<endl;
    }
};
class TRUCK:virtual public CAR{
    protected:
    double load;
    public:
    TRUCK(double a,double b):CAR(a),load(b){
        cout<<"创建货车("<<load<<"吨)"<<endl;
    }
    void Show()const{
        cout<<"货车: "<<speed<<"公里/小时, "<<load<<"吨"<<endl;
    }
};
class VAN:public BUS,public TRUCK{
    public:
    VAN(double a,int b,double c):CAR(a),BUS(a,b),TRUCK(a,c){
        cout<<"创建客货两用车"<<endl;
    }
    void Show()const{
        cout<<"客货两用车: "<<speed<<"公里/小时, "<<seat<<"人, "<<load<<"吨"<<endl;
    }
};
