#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926
class CPoint
{
	double x,y;
public:
	CPoint(double a=0,double b=0)
	{
		x=a;
		y=b;
	}
	CPoint(CPoint &c)
	{
		x=c.x;
		y=c.y;
	}
	virtual double GetArea()
	{
		return 0.0;
	}
	virtual double GetVolume()
	{
		return 0.0;
	}
	void print()
	{
		cout<<"Center:("<<x<<","<<y<<")"<<endl;
	}
	
};

class Cirle:public CPoint
{
protected:
	double radius;
public:
	Cirle(double a,double b,double r):CPoint(a,b)
	{
		radius=r;
	}
	Cirle(Cirle &c)
	{
		radius=c.radius;
	}
	double GetArea()
	{
		return PI*radius*radius;
	}
	virtual double GetVolume()
	{
		return 0.0;
	}
	void print()
	{
		cout<<"radius="<<radius<<endl;
	}	
};

class Cylinder:public Cirle
{
	double height;
public:
	Cylinder(double a,double b,double r,double h):Cirle(a,b,r)
	{
		height=h;
	}
	Cylinder(Cylinder &k):Cirle(k)
	{		
		height=k.height;
	}
	double SupfaceArea()
	{
		return 2*PI*radius*height+PI*radius*radius*2;
	}
	double GetVolume()
	{
		return PI*radius*radius*height;
	}
	void print()
	{
		cout<<"height:"<<height<<endl;
		cout<<"BasalArea:"<<GetArea()<<endl;
		cout<<"SupfaceArea:"<<SupfaceArea()<<endl;
		cout<<"Volume:"<<GetVolume()<<endl;		
	}	
};

int main()
{
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	CPoint cp(a,b);
	Cirle ci(a,b,c);
	Cylinder cy(a,b,c,d);
	cp.print();
	ci.print();
	cy.print();
	return 0;
}
