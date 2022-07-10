class BigInteger
{
private:
    string str;
public:
    BigInteger() {}
    BigInteger(string s)
    {
        str=s;
    }
    friend ostream&operator<<(ostream &os, BigInteger &bigint)
    {
        os<<bigint.str;
        return os;
    }
    friend istream&operator>>(istream &is,BigInteger &bigint)
    {
        is>>bigint.str;
        return is;
    }
    friend BigInteger operator*( BigInteger &bigint1, BigInteger &bigint2);
};
string reserve(string s)
{
    int l=s.length();
    int j=l-1;
    char temp;
    for(int i=0; i<l/2; i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
    return s;
}
 
BigInteger operator*( BigInteger &bigint1, BigInteger &bigint2)
{
    string a=reserve(bigint1.str);
    string b=reserve(bigint2.str);
    if(bigint1.str[0]=='0' || bigint2.str[0]=='0')
    {
        string st="0";
        return BigInteger(st);
    }
    int m,n;
    int *c=new int[a.length()+b.length()+2]();
    for(m=0; m<a.length(); m++)
    {
        for(n=0; n<b.length(); n++)
        {
            c[m+n]+=(a[m]-'0')*(b[n]-'0');
        }
    }
 
    m--;
    n--;
    int carry=0;
    char *ch=new char[a.length()+b.length()+5];
    int p;
    for( p=0; p<=m+n; p++)
    {
        if(c[p]>9)
        {
            ch[p]=(c[p]+carry)%10+'0';
            carry=(c[p]+carry)/10;
        }
        else
        {
            if(carry+c[p]>9)
            {
                ch[p]=(carry+c[p])%10+'0';
                carry=(carry+c[p])/10;
            }
            else
            {
                ch[p]=carry+c[p]+'0';
                carry=0;
            }
        }
 
    }
    if(carry>0)
    {
        ch[p]=carry+'0';
        ch[++p]='\0';
    }
    else
        ch[p]='\0';
    string st(ch);
    string s =reserve(st);
    return BigInteger(s);
 
}