class BigInt{
    string a;
    public:
    BigInt(string a):a(a){}
    BigInt(){a = "";}
    friend istream & operator>>(istream & i, BigInt & B);
    friend ostream & operator<<(ostream & i, const BigInt & B);
    BigInt operator+ ( const BigInt & B1) const;


};

BigInt BigInt::operator + (const BigInt & B1)const
{
    int l1 = B1.a.length();
    int l = this->a.length();
    int carry = 0;
    string res(l1+l, '0');
    for(int i=0;i< l1 && i<l; i++)
    {
        res[i] = (a[l-i-1] + B1.a[l1-i-1] + carry -'0'-'0')%10 +'0';
        carry = (a[l-i-1] + B1.a[l1-i-1] + carry -'0'-'0')/10;
    }
    if(l1<=l)
    {

        for(int i=l1;i<l;i++)
        {
             res[i] = (a[l-i-1]  + carry-'0')%10 +'0';
             carry = (a[l-i-1] + carry -'0')/10;

        }
        res[l] = carry+'0';
    }
    else{
        for(int i=l;i<l1;i++)
        {
             res[i] = (B1.a[l1-i-1]  + carry-'0')%10 +'0';
             carry = (B1.a[l1-i-1] + carry -'0')/10;
        }
        res[l1] = '0'+carry;
    }
    int len = l1+l;
    while(res[len-1]=='0' && len>=2)len--;
    string tmp(len,'0');
    for(int i=0;i<len;i++)
    tmp[i] = res[len-i-1];
     return BigInt(tmp);

}

istream & operator>>(istream & i, BigInt & B)
{
    i >> B.a ;
    return i;
}
ostream & operator<<(ostream & o, const BigInt &  B)
{
    o << B.a;
    return o;
}

