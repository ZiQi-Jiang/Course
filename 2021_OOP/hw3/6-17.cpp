/* 6-17 圆类的定义与使用（拷贝构造函数） (40 分) */
const double PI = 3.14;
class Circle{
    public:
   float m_r;
    Circle(float r):m_r(r){cout<<"Constructor called"<<endl;}
    
    Circle(const Circle & c)
    {
        m_r = c.m_r;
        cout<<"Copy constructor called"<<endl;
    }
    double area(){return m_r*m_r*PI;}
    double perimeter(){ return m_r*2*PI;}
    ~Circle(){cout<<"Destructor called"<<endl;}
};