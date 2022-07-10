/* 6-6 是否是回文 (15 分) */
bool Solution::isPalindrome(char *s)
{
    int len = 0;
    for(int i=0;s[i]!='@';i++)len++;
    for(int i=0;i<len;i++)
        if(s[i]!=s[len-1-i]) return false;
    return true;
}