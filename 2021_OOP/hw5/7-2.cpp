/*R7-2 统计英文段落的字母频度 (15 分)  */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
   string str;
   getline(cin, str);
   for(int i=0;i <26;i++)
   {
       char Upper = 'A'+i;
       char Lower = 'a'+i;
       int freq = 0;
       for(int i=0;i<str.length();i++)
       if(str[i]==Upper || str[i]==Lower)
       freq++;
       printf("\'%c\' or \'%c\' :%d\n",Upper,Lower,freq);
   }
   return 0;
}
