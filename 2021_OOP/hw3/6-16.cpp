/* 6-16 自定义的学生类 (15 分) */
   
    Student::Student(int id,char* name):m_id(id)
    {   strcpy(m_name, name);
        cout<<"Hi!"<<m_id<<" "<<m_name<<endl;}
    Student::~Student(){cout<<"Bye!"<<m_id<<" "<<m_name<<endl;}
  
    
