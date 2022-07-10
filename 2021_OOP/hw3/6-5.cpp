/* 6-5 整数的素因子分解 (30 分) */
/* 
    i * i <= n同意爆精度,导致超时
 */
bool isPrime(int n)
{
    for(long long int i=2;i*i<=n;i++)
        if(n %i == 0) return false;
    return true;
}
void Solution::solve()
{
    const int MAXN=10086;
    int a[MAXN];
    int count = 0;
    cout<<n<<"=";
    if(isPrime(n))
    {
        cout<<n;
    }
    else{
        
    
    for(int i=2;i<=sqrt(n); i++)
         while(n%i==0)
         {
             a[count++] = i;
             n /=i;
         }
    if(n!=1) a[count++] = n;
    
    for(int i=0;i<count;i++)
    {
        if(i)cout<<"*";
        cout<<a[i];
    }
    }
    cout<<endl;
}