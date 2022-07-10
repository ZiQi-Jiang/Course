/* 6-10 学生派生类 (10 分) */
class Student1 : public Student
{
    int age;
    string address;
    public:
    Student1(int n, string nam, char s, int a, string add):Student(n,nam,s),age(a),address(add){}
    void show()
    {
    cout<<"num: "<<num<<endl;
    cout<<"name: "<<name<<endl;
    cout<<"sex: "<<sex<<endl;
    cout<<"age: "<<age<<endl;
    cout<<"address: "<<address<<endl;
    cout<<endl;
}
};