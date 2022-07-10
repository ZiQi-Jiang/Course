vector<int> sieve(int n)
{
    vector<bool> tag(n+1,1);
    tag[0] = tag[1] = false;
    for(int i=2;i<=n;i++)
    if(tag[i])
        for(int k=2;k*i<=n;k++)
            tag[k*i] = false;
    vector<int> res;
    for(int i=0;i<=n;i++)
    if(tag[i]) res.push_back(i);
    return res;

}