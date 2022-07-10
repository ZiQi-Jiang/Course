#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str;
    //cin >> str;
    while (getline(cin, str))
    {
        int From = 0, To = 0, MaxLen = 1;
        int ThisFrom = 0, ThisTo = 0, ThisMaxLen = 1;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
                str[i] += 'a' - '0';
        }
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        //str[str.length()]=0;
       // cout << str << endl;
        for (int i = 1; i < str.length(); i++)
        {
            if (str[i] == str[i - 1])
            {
                ThisTo++;
                ThisMaxLen++;
            }
            else if (ThisMaxLen > MaxLen)
            {
                MaxLen = ThisMaxLen;
                From = ThisFrom;
                To = ThisTo;
                 ThisMaxLen = 1;
                ThisFrom = i;
                ThisTo = i;
            }
            else
            {
                ThisMaxLen = 1;
                ThisFrom = i;
                ThisTo = i;
            }

        }
        if (ThisMaxLen > MaxLen)
            {
                MaxLen = ThisMaxLen;
                From = ThisFrom;
                To = ThisTo;
                 ThisMaxLen = 1;
                ThisFrom = i;
                ThisTo = i;
            }
        cout << "From=" << From + 1 << ",To=" << To + 1 << endl;
        cout << "MaxLen=" << MaxLen << endl;
    }
}