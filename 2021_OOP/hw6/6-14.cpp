/* 6-14 沙发床-虚基类 (10 分) */
class Bed: virtual public Furniture
{
    public:
    void sleep(){cout<<"Sleeping"<<endl;}
    
    
};  
class Sofa: virtual public Furniture
{
    public:
    void watchTV(){cout<<"Watching TV"<<endl;}

};