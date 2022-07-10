#include<iostream>
using namespace std;
#include<deque>
int main()
{
 bool flag=true;
 deque<int> guanzi;
 int n;int c=0;
 scanf("%d",&n);int k=n;
 int s[n];
 while(n--)
 {
 
  int i;
  scanf("%d",&i);
  switch(i)
  {
   case 1: 
   int x;
   scanf("%d",&x);
   if (flag) guanzi.push_back(x);
   else guanzi.push_front(x);
   break;
   
   case 2:
   if(!guanzi.empty())
   {if (flag)
   guanzi.pop_front();
   else guanzi.pop_back();
   }
   else break;
   break;
   case 3:
   flag = !flag; break;
   default:
    break;
  }
  if(!guanzi.empty()) s[c]=(guanzi.back()^guanzi.front());
  else s[c]=-1;
  c++;
 }
 for(int j=0;j<k;j++)
 printf("%d\n",s[j]);
}