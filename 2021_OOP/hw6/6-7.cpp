/* 6-7 派生类使用基类的成员函数 (10 分) */
class Animal
{
    int m_nWeightBase;
    protected:
    int m_nAgebase;
    public:
    void set_weight(int w){m_nWeightBase = w;}
    int get_weight(){ return m_nWeightBase;}
    void set_age(int a){ m_nAgebase = a;}
    
};
class Cat: public Animal
{
   string m_strName;
   public:
   Cat(string name):m_strName(name){}
   void print_age(){ cout<<"Persian, age = "<<m_nAgebase<<endl;}
   
};