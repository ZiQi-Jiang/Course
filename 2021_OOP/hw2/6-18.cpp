class Circle
{
    private:
    Point ctr;
    double r;
    public:
    Circle(Point ctr_,double r_):ctr(ctr_),r(r_){};
    char* judge(const Point & p)
    {
        char* a[3] = {"inside","on","outside"};
        double dist = ctr.distance(p);
        if(dist<r) return a[0];
        else if(dist==r) return a[1];
        else return a[2];
    }
};
Point::Point(){}
Point::Point(double x_, double y_):x(x_),y(y_){}
double Point::distance()
{
    return sqrt(x*x + y*y);
}
double Point::distance(const Point & p)
{
    double m = (x-p.x)*(x-p.x);
    double n = (y-p.y)*(y-p.y);
    return sqrt(m+n);
}

void Point::setX(double x_){x = x_;}
void Point::setY(double y_){y = y_;}