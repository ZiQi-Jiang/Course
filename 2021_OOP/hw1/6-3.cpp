bool s2(const Student &a, const Student &b) //a b  为哪个学生 a学生 b学生  比较 a b 数学和英语成绩 b大则返回true
{
    if(a.score[0]+a.score[1]>b.score[0]+b.score[1])
    {
        return true;
    }
    else if((a.score[0]+a.score[1]==b.score[0]+b.score[1])&&(a.num<b.num))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool s4(const Student &a, const Student &b) //比较 a b 总分 b大返回true
{
    if(a.score[0]+a.score[1]+a.score[2]+a.score[3]>b.score[0]+b.score[1]+b.score[2]+b.score[3])
    {
        return true;
    }
    else if((a.score[0]+a.score[1]+a.score[2]+a.score[3]==b.score[0]+b.score[1]+b.score[2]+b.score[3])&&(a.num<b.num))
    {
        return true;
    }
    else
    {
        return false;
    }
}
int select(Student st[],int n,bool (*s)(const Student &a,const Student &b))//挑选人数的分数最高的一个 用for循环
{
    int maxmax=0,i;//先定义初始值
    for(i=1; i<n; i++)//用for 循环比较 分数最多的那个
    {
        if(s(st[maxmax],st[i]))
    {
        continue;//相等的 话 持续 进行for循环
    }
    else
    {
        maxmax=i;
    }
}
return st[maxmax].num;
}
