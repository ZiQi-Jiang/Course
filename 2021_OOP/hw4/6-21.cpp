/* 请在这里填写答案 */
Student::Student(int id,char *name)
{
    m_id = id;
    strcpy(m_name,name);
    cout<<"Hi!"<<m_id<<" "<<m_name<<endl;
}
Student::~Student()
{
    cout<<"Bye!"<<m_id<<" "<<m_name<<endl;
}
void Student::print()
{
    cout<<m_id<<" "<<m_name<<endl;
}
