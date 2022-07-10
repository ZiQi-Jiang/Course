class MyDate{
private:
    int m,d,y;
public:
    MyDate(int pm=1,int pd=1,int py=1900){
        m=pm;d=pd;y=py;
    }
    void setDate(int m,int pd,int year){
        bool rn=false;
        rn = ((0 == year % 4) && (0 != year % 100)) || (0 == year % 400);
        bool err=((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&pd>31)||
                 ((m==4||m==6||m==9||m==11)&&pd>30)||(m==2&&rn&&pd>29||!rn&&m==2&&pd>28)||m>12;
        if(err){
            m=1;d=1;y=1900;
        }else{
            this->m=m;d=pd;y=year;
        }
    }
    MyDate operator++(){
        bool rn=false;
        rn = ((0 == y % 4) && (0 != y % 100)) || (0 == y % 400);
        ++d;
        bool err=((m==1||m==3||m==5||m==7||m==8||m==10||m==12)&&d>31)||
                 ((m==4||m==6||m==9||m==11)&&d>30)||(m==2&&rn&&d>29||!rn&&m==2&&d>28);
        if(err){
            d=1;
            m++;
            if(m>12){
                m=1;
                y++;
            }
        }
        return *this;
    }
    MyDate operator++(int){
        MyDate md=*this;
        operator++();
        return md;
    }
    MyDate operator+=(int day){
        for (int i = 0; i <day ; ++i) {
            operator++();
        }
        return *this;
    }
    friend ostream& operator<<(ostream & outd,MyDate md);
};
ostream& operator<<(ostream & outd,MyDate md){
    string month[12]={"January","February","March","April","May","June","July",
                        "August","September","October","November","December"};
    outd<<month[md.m-1]<<' '<<md.d<<", "<<md.y;
    return outd;
}