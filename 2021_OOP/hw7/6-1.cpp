/* 
    虚函数的使用
    静态变量共享
    protected
    抽象类
 */

class Student
{
protected:
    string num, name;

public:
    static double gradeline;

public:
    virtual void display() = 0;
    Student(string num, string name) : num(num), name(name)
    {
    }
    virtual ~Student() {}
};

class GroupA : public Student
{
    int s1, s2;

public:
    void display();
    GroupA(string num, string name, int s1, int s2) : s1(s1), s2(s2), Student(num, name)
    {
        double avg = (s1 + s2) / 2.0;
        if (avg > Student::gradeline)
            Student::gradeline = avg;
    }
};
class GroupB : public Student
{
    int s1, s2;
    char gs;

public:
    void display();
    GroupB(string num, string name, int s1, int s2, char gs) : s1(s1), s2(s2), gs(gs), Student(num, name)
    {
        double avg = (s1 + s2) / 2.0;
        if (avg > Student::gradeline)
            Student::gradeline = avg;
    }
};

class GroupC : public Student
{
    int s1, s2, s3, s4, s5;

public:
    void display();
    GroupC(string num, string name, int s1, int s2, int s3, int s4, int s5) : s1(s1), s2(s2), s3(s3), s4(s4), s5(s5), Student(num, name)
    {
    }
};

double Student::gradeline = 0;

void GroupA::display()
{
    double avg = (s1 + s2) / 2.0;
    if (avg == Student::gradeline)
        cout << num << " " << name << endl;
    return;
}

void GroupB::display()
{
    double avg = (s1 + s2) / 2.0;
    if (((avg >= 0.7 * Student::gradeline) && gs == 'A') || avg == Student::gradeline)
        cout << num << " " << name << endl;
    return;
}

void GroupC::display()
{
    double avg = (s1 + s2 + s3 + s4 + s5) / 5.0;
    if (avg >= 0.9 * Student::gradeline)
        cout << num << " " << name << endl;
    return;
}
