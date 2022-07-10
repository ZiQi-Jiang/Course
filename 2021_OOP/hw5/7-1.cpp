#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;



int main()
{
    double x1,y1,x2,y2;
    cin >> x1 >> y1 >>x2>>y2;
    double res_2 = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    printf("%.2f", sqrt(res_2));
   
   return 0;
}
