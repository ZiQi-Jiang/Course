
/* 打98折 */
#include <iomanip>
#include <iostream>
 
using namespace std;
 
int main(void)
{
	double sum = 0;
	int n = 0;
 
	for (int i = 0; i < 3; ++i)
	{
		double y;
		int x;
		
		cin >> x >> x >> y;
		
		if (x > 10)
		{
			y *= 0.98;	
		}
		
		sum += y*x*0.95;
		n += x;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(2) << sum << endl
		 << setiosflags(ios::fixed) << setprecision(2) << sum/n << endl;
		 
	return 0;
}
