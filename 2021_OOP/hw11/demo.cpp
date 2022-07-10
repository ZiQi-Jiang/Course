#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class A{
	static int count;
	
};
int A::count = 0;
int main()
{
   A a;
   cout<<A::count<<endl;
}