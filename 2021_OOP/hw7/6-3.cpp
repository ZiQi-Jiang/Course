
class CMyClassB:public CMyClassA{
    int valB;
    public:
    CMyClassB(int arg):valB(arg),CMyClassA(3*arg){
        printf("B:%d\n",valB);
    }
    void print()
    {
        printf("%d\n",valB);


    }
};

