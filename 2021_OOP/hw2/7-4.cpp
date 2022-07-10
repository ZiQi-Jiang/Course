/* 7-11 复数的运算 (10 分) */
#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

enum Domain{INT =0,DOUBLE};
class Complex{
    public:
    Domain domain;
    double real_1,image_1,real_2,image_2;
    void get_value()
    {
        double a,b,c,d;
        char op;
        cin>>a>>op>>b>>op>>c>>op>>d;
        if(a==int(a)) domain = INT;
        else domain = DOUBLE;
        if(domain==INT)
        {
            real_1 = int(a);
            real_2 = int(c);
            image_1 = int(b);
            image_2 = int(d);
        
        }
        else
        {
            real_1 = a;
            real_2 = c;
            image_1 = b;
            image_2 = d;
        }
    }
  

};

  void display(double real_1, double image_1)
    {
        if(real_1==0 && image_1==0)printf("[0]\n");
        else if(real_1==0)
        {
        if(image_1 == int(image_1))
        printf("[%di]\n",int(image_1));
        else printf("[%.3fi]\n",image_1);
        }
        else if(image_1==0)
        {
        if(real_1==int(real_1))
        printf("[%d]\n",int(real_1));
        else  printf("[%.3f]\n",real_1);
        }
        else if(image_1>0)
        {
            if(real_1 == int(real_1))
            printf("[%d+",int(real_1));
            else printf("[%.3f+",real_1);
             if(image_1 == int(image_1))
            printf("%di]\n",int(image_1));
            else printf("%.3fi]\n",image_1);
        //printf("[%g+%gi]\n",real_1,image_1);
        }
        else 
        {
            
            if(real_1 == int(real_1))
            printf("[%d",int(real_1));
            else printf("[%.3f",real_1);
             if(image_1 == int(image_1))
            printf("%di]\n",int(image_1));
            else printf("%.3fi]\n",image_1);

        }
        //printf("[%g%gi]\n",real_1,image_1);

    }

int main()
{
   Complex c;
   c.get_value();
   display(c.real_1,c.image_1);
   display(c.real_2,c.image_2);
   display(c.real_1+c.real_2,c.image_1+c.image_2);
   double queo = (c.real_2*c.real_2 + c.image_2*c.image_2);
   double n1 = c.real_1*c.real_2 + c.image_1*c.image_2;
   double n2 = c.image_1*c.real_2 - c.real_1*c.image_2;
   if(c.domain==INT)display(double(int(n1)/int(queo)),double(int(n2)/int(queo)));
   else display(n1/queo,n2/queo);
   if(c.real_1>c.real_2) cout<<1<<endl;
   else if(c.real_1 < c.real_2) cout<<-1<<endl;
   else if(c.image_1> c.image_2)cout<<1<<endl;
   else if(c.image_1 < c.image_2)cout<<-1<<endl;
   else cout<<0<<endl;
   return 0;
}
