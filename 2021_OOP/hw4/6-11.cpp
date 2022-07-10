class Str
{
    char m_t[30];
    int len;
    char c;
    public:
    Str(char* t)
    {
        strcpy(m_t,t);
    }

    void process();
    void print();
};

void Str::print()
{
    cout<<m_t<<endl;
    for(int i=1;i<=len;i++) putchar(c);
    cout<<endl<<len<<endl;
}

void Str::process()
{
    len = 1;
    int thislen = 0; 
    char thisc = m_t[0];
    int L = strlen(m_t);
    c = m_t[0]; thislen = 1;
    for(int i=1;i<=L;i++)
    {
        if(m_t[i]==thisc) thislen++;
        else{
            if(thislen>len)
            {
                len = thislen;
                c = thisc;
            }
            thislen = 1;
            thisc =  m_t[i];
        }
        
    }
}