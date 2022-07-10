template<class T>
class MyArray{
    int size;
    T* data;
    public:
    MyArray(int s);
    void sort();
    bool check();
    void display();
    ~MyArray();
    
};
template<class T>
MyArray<T>::MyArray(int s){
    size = s;
    if(size==0) data = NULL;
    else data = new T[size];
    for(int i=0;i<size;i++)
    cin >> data[i];
    

}

template<class T>
void MyArray<T>::sort()
{
    for(int i=0;i<size;i++)
     for(int j=0;j<size-i-1;j++)
       if(data[j]>data[j+1]) swap(data[j],data[j+1]);

}

template<class T>
void MyArray<T>::display()
{
    for(int i=0;i<size-1;i++)
    cout<<data[i]<<" ";
    if(size>0)
    cout<<data[size-1];
    cout<<endl;
}
