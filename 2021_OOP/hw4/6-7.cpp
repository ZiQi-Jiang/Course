/* 6-7 类的声明与成员函数的实现--Car类 (10 分) */
    int Car::get_wheels(){ return m_nWheels;}
    void Car::set_wheels(int x){ m_nWheels = x; }
void Car::disp_welcomemsg()
{
    cout<<"Welcome to the car world!"<<endl;
}