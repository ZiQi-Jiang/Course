class Point
{
    public:
    int x,y;
    static int num ;
    public:
    Point(){ x=0;y=0; num++;}
    Point(int x_):x(x_){num++;}
    Point(int x_, int y_):x(x_),y(y_){num++;}
    Point(const Point & a)
    {
        x = a.x; y = a.y;
        num++;
    }
    int getX(){ return x;}
    int getY(){ return y;}
    static void showCount()
    {
      cout<<num<<endl;
    }
};
int Point::num=0;