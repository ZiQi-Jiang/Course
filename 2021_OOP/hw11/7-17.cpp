#include <iostream>
#include <cstdio>
#include <cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long int a[1000005];
int main()
{
    long long int n, m, left, right, s = 0;
    scanf("%lld %lld", &n,&m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);				//对n个数据进行排序
    for (int i = 1; i < n; i++)  		//将m值插入进去后，获取m左边的值left与右边的值right
    {
        if (m <= a[0])			//特判m是否比第一个值还小
        {
            left = -1;
            s = s + a[0] - m;
            m = a[0];
            right = 1;
            break;
        }
        if (m > a[n - 1])		//特判m是否比最后一个值还大
        {
            right = n;
            s = s + m - a[n - 1];
            m = a[n - 1];
            left = n - 2;
            break;
        }
        if (m >= a[i - 1] && m <= a[i])		//遍历搜索m在n个数据中，排到哪个位置
        {
            long long int sl,sr;
            sl = m - a[i-1];
            sr = a[i] - m;
            if (sl <= sr)
            {
                s = s + sl;
                m = a[i - 1];
                left = i - 2;
                right = i;
                break;
            }
            else
            {
                s = s + sr;
                m = a[i];
                left = i - 1;
                right = i+1;
                break;
            }
        }
    }
    while (left != -1 && right!=n)	//开始左右比较，并且累加s，替换m值
    {
        long long int sl, sr;
        sl =m-a[left];
        sr = a[right]-m;
        if (sl <= sr)
        {
            s = s + sl;
            m = a[left];
            left--;
        }
        else
        {
            s = s + sr;
            m = a[right];
            right++;
        }
    }
    if (left == -1)		//若m到达最左边后，只需不断计算右边没计算的值
    {
        while (right != n)
        {
            long long int sr;
            sr = a[right]-m;
            s = s + sr;
            m = a[right];
            right++;
        }
    }
    if (right == n)		//若m到达最右边后，只需不断计算左边没计算的值
    {
        while (left != -1)
        {
            long long int sl;
            sl = m - a[left];
            s = s + sl;
            m = a[left];
            left--;
        }
    }
    printf("%lld\n", s);
 
    return 0;
}
