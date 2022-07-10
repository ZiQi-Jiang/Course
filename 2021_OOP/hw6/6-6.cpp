/* 6-6 派生类的定义和使用 (10 分) */
class Cat
{
    string m_strName;
    public:
    Cat(string name):m_strName(name){}
    void print_name(){cout<<"cat name: "<<m_strName<<endl;}
    void speak()
    {
        cout<<"animal language!"<<endl;
    }
};
