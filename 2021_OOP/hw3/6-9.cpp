TDVector(double _x, double _y):x(_x), y(_y){}
double getX  ()const{ return x;}
double getY ()const{ return y;}
void setX(double _x){ x = _x;}
void setY(double _y){ y = _y;}
 TDVector operator + (const TDVector & t2)
{
    return TDVector(x+ t2.getX(), y+t2.getY());
 
}