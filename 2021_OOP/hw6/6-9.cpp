/* 6-9 学生信息输入输出 (10 分) */
class Student1: public Student
{
    public:
    void get_value_1(){ cin >> age >> country;}
    void display_1()
    {
    cout<<"age: "<<age<<endl;
    cout<<"address: "<<country<<endl;
}
    private: int age;string country;
};