template<class T>
void sort(T*a, int size)
{
    for(int i=0;i<size;i++)
    cin >> a[i];
    for(int i=0;i<size;i++)
    for(int j=0;j<size-i-1;j++)
    if(a[j]>a[j+1]) swap(a[j],a[j+1]);
}