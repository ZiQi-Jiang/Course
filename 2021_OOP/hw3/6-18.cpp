/* 6-18 水上飞机(*) (20 分) */
#include <iostream>
using namespace std;

/* 你提交的代码将被嵌在这里 */
#include<cstdio>
class CRAFT{
    protected:
  double speed; 
    public:
  CRAFT( double _speed):speed(_speed)
  {printf("创建航行器(速度: %g)\n",speed);}
   virtual void Show()
   {
       printf("航行(速度: %g)\n",speed);
   }
   virtual ~CRAFT()
    {
        
        printf("销毁航行器(速度: %g)\n",speed);
    }
};

class PLANE:virtual public CRAFT
{
    protected:
    double width;
    public:
    PLANE(double _speed, double _width):CRAFT(_speed),width(_width)
    {
    printf("创建飞机(翼展: %g)\n",width);
    }
    void Show()
    {
    printf("航行(速度: %g, 翼展: %g)\n",speed,width);
    }
    ~PLANE()
    {
        printf("销毁飞机(翼展: %g)\n",width);
    }
    
};

class SHIP:virtual public CRAFT
{
    protected:
    double depth;
    public:
    SHIP(double _speed, double _depth):CRAFT(_speed),depth(_depth)
    {
    printf("创建船(吃水: %g)\n",depth);
    }
  
    virtual void Show()
    {
    printf("航行(速度: %g, 吃水: %g)\n",speed,depth);
    }
    ~SHIP()
    {
    printf("销毁船(吃水: %g)\n",depth);
    }
};

class SEAPLANE: public PLANE, public SHIP
{
public:
    SEAPLANE(double speed, double width, double depth):CRAFT(speed),PLANE(speed, width),SHIP(speed,depth)
    {
    printf("创建水上飞机\n");
    }
    virtual void Show()
    {
    printf("航行(速度: %g, 翼展: %g, 吃水: %g)\n",speed,width,depth);
    }
    ~SEAPLANE()
    {
    printf("销毁水上飞机\n");
    }
};
int main()
{
    CRAFT *p;
    p = new SEAPLANE(415.2, 36.5, 2.1);
    // p = new SHIP(45.8, 8.3);
    // p = new PLANE(613.5, 45.3);
    // p = new CRAFT(87.2);
    //p = new SEAPLANE(415.2, 36.5, 2.1);
    p->Show();
    delete p;
    return 0;
}
