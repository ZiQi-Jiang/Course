#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>

int m, n;
char a[10010][10010];
bool flag[10010][10010];
using namespace std;

void Test(int i, int j)
{
    switch (a[i][j])
    {
    case 'o':
        if (a[i + 1][j - 1] == '/')flag[i + 1][j - 1] = false;
        if (a[i + 1][j] == '|')flag[i + 1][j] = false;
        if (a[i + 1][j + 1] == '\\')flag[i + 1][j + 1] = false;
        if (a[i + 2][j - 1] == '(')flag[i + 2][j - 1] = false;
        if (a[i + 2][j + 1] == ')')flag[i + 2][j + 1] = false;
        break;
    case '/':

        if (a[i][j + 1] == '|')flag[i][j + 1] = false;
        if (a[i][j + 2] == '\\')flag[i][j + 2] = false;
        if (a[i + 1][j] == '(')flag[i + 1][j] = false;
        if (a[i + 1][j + 2] == ')')flag[i + 1][j + 2] = false;
        break;
    case '|':
        if (a[i][j + 1] == '\\')flag[i][j + 1] = false;
        if (a[i + 1][j - 1] == '(')flag[i + 1][j - 1] = false;
        if (a[i + 1][j + 1] == ')')flag[i + 1][j + 1] = false;
        break;
    case '\\':

        if (a[i + 1][j - 2] == '(')flag[i + 1][j - 2] = false;
        if (a[i + 1][j] == ')')flag[i + 1][j] = false;
        break;
    case '(':
        if (a[i][j + 2] == ')')flag[i][j + 2] = false;
        break;
    }
}
void Solve()
{
      getchar();
    int res = 0;
    for (int i = 2; i <= n + 1; i++)
    {

        for (int j = 2; j <= m + 1; j++)
        {
            a[i][j] = getchar();
            if (a[i][j] != ' ') flag[i][j] = true;
            else flag[i][j] = false;
        }
        getchar();
    }
    for (int i = 2; i <= 1 + n; i++)
        for (int j = 2; j <= 1 + m; j++)
            if (flag[i][j])
                Test(i, j);
    for (int i = 2; i <= 1 + n; i++)
        for (int j = 2; j <= 1 + m; j++)
            if (flag[i][j]) res++;
    cout << res<<endl;
}
int main()
{

    while(cin>>n>>m) Solve();
  
    return 0;
}
