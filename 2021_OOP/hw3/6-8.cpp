#include<iostream>
using namespace std;
class Complex
{
    public:
    int real,image;
    public:
    Complex(int r=0,int i = 0):real(r), image(i){}
    Complex(const Complex & c)
    {
        real = c.real; image = c.image;
    }
    void Display()
    {
        cout<<real;
        if(image<0)cout<<image;
        else cout<<"+"<<image;
        cout<<"i"<<endl;
    }
   
};
 Complex AddComplex(const Complex & c1, const Complex & c2)
    {
        return Complex(c1.real+c2.real, c1.image + c2.image);
    }
     