/* 6-1 类的声明和成员函数的实现--this指针 (10 分) */
class Car
{
    public:
    void disp_welcomemsg();
    int get_wheels(){ return m_nWheels;}
    void set_wheels(int x){ m_nWheels = x; }
    private:
    int m_nWheels;
};
void Car::disp_welcomemsg()
{
    cout<<"Welcome to the car world!"<<endl;
}