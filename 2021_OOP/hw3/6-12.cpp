/* 6-12 定义Date类 (10 分) */
class Date
{
    int day,month,year;
    public:
    Date(int day=1, int month=1, int year=2019):day(day),month(month),year(year){}
    void display()
    {
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};