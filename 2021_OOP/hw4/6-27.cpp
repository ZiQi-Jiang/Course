/*6-27 日期类 - 1. 判断闰年 (10 分)  */
bool MYDATE::IsLeapYear( int year)
{
    if((year % 4==0 && year %100!=0) || (year%400==0)) return true;
    return false;
}