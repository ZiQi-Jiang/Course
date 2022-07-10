#include<iostream>
using namespace std;
int main()
{
 long t, a, b, a0, b0, x, y, n0, n, i, r1, r2;
 cin >> t;
 for (i = 1; i <= t; i++)
 {
  cin >> a0 >> b0 >> x >> y >> n0;
  a = a0;
  b = b0;
  n = n0;
  r1 = a * b;
  r2 = a * b;
  if (n >= (a - x))
  {
   n = n - (a - x);
   a = x;
   if (n >= (b - y))
   {
    r1 = x * y;
   }
   else
   {
    b = b - n;
    r1 = a * b;
   }
  }
  else if (n < (a - x))
  {
   a = a - n;
   r1 = a * b;
  }
  a = a0;
  b = b0;
  n = n0;
  if (n >= (b - y))
  {
   n = n - (b - y);
   b = y;
   if (n >= (a - x))
   {
    r2 = x * y;
   }
   else
   {
    a = a - n;
    r2 = a * b;
   }
  }
  else if(n < (b-y))
  {
   b = b - n;
   r2 = a * b;
  }
  if (r1 >= r2)
   cout << r2 << endl;
  else
   cout << r1 << endl;
 }

}
