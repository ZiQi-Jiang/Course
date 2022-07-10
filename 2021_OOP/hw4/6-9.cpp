/* 6-9 实现数组类（C++ 拷贝构造函数、拷贝函数） (10 分) */
Array(int k){ size = k;data = new int[size]();}

Array( Array & b)
{
    size = b.size;
    data = new int[size]();
    for(int i=0;i<size;i++) data[i] = b[i];
}

Array &  operator = ( Array & b)
{
    if(this == & b) return *this;
    delete [] data;
    size = b.size;
    data = new int[size]();
    for(int i=0;i<size;i++)data[i] = b[i];
    return *this;
    
}
~ Array()
{
    delete [] this->data;
}