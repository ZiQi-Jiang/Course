#include<bits/stdc++.h>

#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define sc(a) scahf("%c",&a);
#define ss(a) scanf("%s",a)
#define pi(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define pc(a) putchar(a)
#define ms(a) memset(a,0,sizeof(a))
#define repi(i, a, b) for(register int i=a;i<=b;++i)
#define repd(i, a, b) for(register int i=a;i>=b;--i)
#define reps(s) for(register int i=head[s];i;i=Next[i])
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define pii pair<int,int>
#define mii unordered_map<int,int>
#define msi unordered_map<string,int>
#define lowbit(x) ((x)&(-(x)))
#define ce(i, r) i==r?'\n':' '
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define INF 0x3f3f3f3f
#define pr(x) cout<<#x<<": "<<x<<endl
using namespace std;

inline int qr() {
    int f = 0, fu = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')fu = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        f = (f << 3) + (f << 1) + c - 48;
        c = getchar();
    }
    return f * fu;
}

const int N = 1e5 + 10;
int n, m;
ll s;
int q[N];

int main() {
    n = qr(), m = qr(), sl(s);
    if (s <= 0) {
        repi(i, 1, n)repi(j, 1, m)if (qr() >= s) {
                    puts("1");
                    return 0;
                }
        puts("-1");
        return 0;
    }
    vector<vector<ll> > sum(min(n, m) + 1, vector<ll>(max(n, m) + 1));
    if (n > m) {
        repi(i, 1, n)repi(j, 1, m)sum[j][i] = sum[j - 1][i] + sum[j][i - 1] - sum[j - 1][i - 1] + qr();
        swap(n, m);
    } else
        repi(i, 1, n)repi(j, 1, m)sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + qr();
    int ans = INF;
    repi(i, 1, n) repi(j, i, n) {
            int l = 1, r = 1; q[1] = 0;
            repi(t, 1, m) {
                ll now = sum[j][t] - sum[i - 1][t];
                while ((l + 1 <= r) && (now - (sum[j][q[l + 1]] - sum[i - 1][q[l + 1]])) >= s)l++;
                if (now - (sum[j][q[l]] - sum[i - 1][q[l]]) >= s)ans = min(ans, (j - i + 1) * (t - q[l]));
                while ((l <= r) && (sum[j][q[r]] - sum[i - 1][q[r]] >= now))r--;
                q[++r] = t;
            }
        }
    ans == INF ? puts("-1") : pi(ans);
    return 0;
}
