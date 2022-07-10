/* 6-12 虚基类的应用-人与教师学生 (10 分) */
class Graduate: public Teacher, public Student
{
    double wages;
    public:
    Graduate(string name,char sex, int age, string title, double score, double wages):
    Person(name, sex, age),Teacher(name, sex, age, title),
    Student(name, sex, age, score){this->wages = wages;}
    void show()
    {

 cout<<"name:"<<name<<endl;
     cout<<"age:"<<age<<endl;
     cout<<"sex:"<<sex<<endl;
     cout<<"score:"<<score<<endl;
     cout<<"title:"<<title<<endl;
     cout<<"wages:"<<wages<<endl;
}
};