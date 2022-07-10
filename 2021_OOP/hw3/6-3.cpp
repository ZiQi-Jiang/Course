/* 6-3 学生成绩的快速录入（构造函数） (10 分) */
// copy constructor 
//display
class Student{
     public: int no,score;
    static int count;
    Student(int _no, int _score): no(_no), score(_score){ count++;}
    Student( const Student & a)
    {
        this->no = a.no+1;
        this->score = a.score;
        count ++;
    }
    void display()
    {
        cout<<no<<" ";
        if(score==0) cout<<"Fail"<<endl;
        else cout<<"Pass"<<endl;
        
    }
    
    
};
int Student::count = 0;