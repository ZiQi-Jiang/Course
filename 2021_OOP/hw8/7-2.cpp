#include <iostream>
using namespace std;
class Complex
{
	public:
		Complex(double r=0, double i=0):real(r), imag(i){	}
		Complex operator+(Complex c) const;
		Complex operator-=(Complex c); 
		friend const Complex operator-(Complex c1,Complex c2) ;
		void Display() const;
	private:
		double real;
		double imag;
};
Complex Complex::operator+ (Complex c)const{

return Complex(real+c.real,imag+c.imag);
}
Complex Complex::operator-=(Complex c){
this->imag=this->imag-c.imag;
this->real=this->real-c.real;
return *this;
 
}
const Complex operator-(Complex c1,Complex c2){
c1.imag=c1.imag-c2.imag;
c1.real=c1.real-c2.real;
return c1;
}
 
void Complex::Display() const
{
	cout << "(" << real << ", " << imag << ")" << endl;
}
 
int main()
{
	double r, m;
	cin >> r >> m;
	Complex c1(r, m);
	cin >> r >> m;
	Complex c2(r, m);
	Complex c3 = c1+c2;
	c3.Display();
	c3 = c1-c2;
	c3.Display();
	c3 -= c1;
	c3.Display();
	return 0;
}