/*  6-28 日期类 - 2. 求月天数 (10 分*/
int MYDATE::MaxDayMonth(int year, int month)
{
    int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(MYDATE::IsLeapYear && month == 2) return 29;
    else return day[month];
}