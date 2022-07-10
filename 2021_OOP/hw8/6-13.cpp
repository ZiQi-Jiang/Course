class CComplex
{	 
	public:
	CComplex(){real=0;imag=0;}//无参构造函数 
	CComplex(double r, double i){ real=r, imag=i;}//有参构造函数 
	friend istream &operator <<(istream &  ,CComplex & );//输入流重载
	friend ostream &operator >>(ostream &  ,CComplex & );//输出流重载    固定格式 友元函数； 
		CComplex operator+(CComplex c)	{
  		return CComplex(real+c.real,imag+c.imag);
	  }
  	CComplex operator-(CComplex c){
		return CComplex(real-c.real,imag-c.imag);
	}
       	double real,imag;
};
istream &operator >>(istream & is,CComplex &c){
    is>>c.real>>c.imag;
  return is;
}
ostream &operator <<(ostream & os ,CComplex& c ){
    os<<c.real<<showpos<<c.imag<<"i"<<noshowpos<<endl;
  return os;
}