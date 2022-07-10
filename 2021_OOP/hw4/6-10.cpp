class ID
{
    char oldID[15];
    char newID[18];
    bool flag ;
    public:
    ID(char* oldID_)
    {
        for(int i=0;i<15;i++) oldID[i] = oldID_[i];
        flag = false;
    }

    void print()
    {
        if(!flag)
        for(int i=0;i<15;i++) putchar(oldID[i]);
        else 
        for(int i=0;i<18;i++)  putchar(newID[i]);
        cout<<endl;
    }

    void convert()
    {
        int weight[] ={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
        char last[] = {'1','0','X','9','8','7','6','5','4','3','2'};
        int res = 0;
        for(int i=0;i<6;i++) newID[i] = oldID[i];
        newID[6] = '1';newID[7] = '9';
        for(int i=8;i<17;i++) newID[i] = oldID[i-2];

        for(int i=0;i<17;i++) res+= (newID[i] - '0')*weight[i];
        newID[17] = last[res%11];
        flag = true;
    }
};
