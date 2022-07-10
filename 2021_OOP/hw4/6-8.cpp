/* 6-8 统计数字 (15 分) */
class Solution{
    public:
    int count_digits(const string & s)
    {
        int num = 0;
        for(int i=0;i<s.length();i++)
            if(s[i]>='0' && s[i]<='9') num++;
       return num;
    }
};