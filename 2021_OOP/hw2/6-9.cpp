#include<algorithm>
class Solution{
	public:
		int count_digits(string str)
		{
			int num = 0;
			for(int i=0;i<10;i++)
			  num += count(str.begin(),str.end(),'0'+i);
			return num;
		}
};