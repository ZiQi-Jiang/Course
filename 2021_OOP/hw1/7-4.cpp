/* 7-4 Walking in the Sun (10 分) */
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int MAXV=500;
double dis[MAXV][MAXV];
int n;
struct Point{
  double x,y,r;
}p[MAXV];

void Floyd(){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if(dis[i][k]+dis[k][j]<dis[i][j])
        dis[i][j]=dis[i][k]+dis[k][j];
      }
    }
  }
}
int main(){
  int N,shade,q;
  double x1,x2,y1,y2; 
  int u,v; 
  cin>>N;
  for(int i=0;i<N;++i){
    cin>>shade;
    if(i!=0) printf("\n");
    cout<<"Campus #"<<i+1<<":"<<endl;
    for(int j=1;j<=shade;++j){
      scanf("%lf %lf %lf\n",&p[j].x,&p[j].y,&p[j].r);
    }
    cin>>q;
    for(int j=0;j<q;++j){
      scanf("%lf %lf %lf %lf\n",&x1,&y1,&x2,&y2);
      p[0].x=x1;p[0].y=y1;p[shade+1].x=x2;p[shade+1].y=y2;
        p[0].r=p[shade+1].r=0.0;
        n=shade+2;
      double dist;
    for(u=0;u<n;++u){
      for(v=0;v<n;++v){
          dist=sqrt(pow(p[u].x-p[v].x,2)+pow(p[u].y-p[v].y,2))-p[u].r-p[v].r;
          if(dist<0) dist=0;
          dis[u][v]=dis[v][u]=dist;
      }
    }
    Floyd();
    printf("  Path #%d: Shortest sun distance is %.1f.\n",j+1,dis[0][shade+1]);
  }
}
  return 0;
}
