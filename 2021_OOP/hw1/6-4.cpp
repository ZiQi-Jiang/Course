
bool test(int a[N][N],int j,int k)
{
     bool visited [N];
    for(int i=0;i<N;i++)
        visited[i] = false;
    visited[j] = true;
    
    while(1)
    {
        bool flag = false;
      for(int i=0;i<N;i++)
          if(!visited[i])
          {
            for(int m=0;m<N;m++)
                if(a[i][m] && visited[m]) 
                {
                     visited[i] = true;flag = true;
                    break;
                }
                   
          }
       if(flag==false) break;
    }
    if(visited[k]) return true;
    return false;
}

