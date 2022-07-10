#include<string.h>
template<class T>
class Vector{
    int size;
    T* ptr;
    public:
    Vector(){size = 0; ptr = NULL;};
    int get_size(){return size;}
    T& operator[](int i){return ptr[i];}
    void  remove(int m);
    Vector( Vector & a);
    //friend ostremam & operator<<(ostream & o, Vector a)
    int add(T x);
};


template<class T>
Vector<T>::Vector(Vector & a)
{
    if(a.ptr==NULL)
    {
        ptr = NULL;
        size = 0;
    
    }
    else{

    ptr = new T[a.size];
    memcpy(ptr,a.ptr,sizeof(T)*a.size);
    size = a.size;
    }
    
}

template<class T>
int Vector<T>::add(T x)
{
    int res = size;
    T* tmpPtr = new T[size+1];
    memcpy(tmpPtr, ptr, sizeof(T)*size);
    delete ptr;
    ptr = tmpPtr;
    ptr[size++] = x;
    return res;

}

template<class T>
void Vector<T>::remove(int m)
{
    for(int i=m;i<size-1;i++)
    ptr[i] = ptr[i+1];
    size--;
    
}
