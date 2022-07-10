/* 数组类的实现 */
    Array( int n )
{
    size = n;
    data = new int[n];
}

Array( const Array & a)
{
    size = a.size;
    data = new int[size];
    for(int i = 0; i < size; i++)
    data[i] = a.data[i];
}

 Array &  operator = (Array & b)
 {
    if(this != &b)  //内存超限
    {
         delete []data; 
         size = b.size;
        
         data = new int[size];
         for( int i=0; i < size; i++)
         this->data[i] = b.data[i];
    }

         return *this;
 }

~ Array()
{
    if(this->data != NULL)  delete []data;
}