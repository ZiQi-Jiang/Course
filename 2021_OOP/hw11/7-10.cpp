#include<bits/stdc++.h>

using namespace std;
const int N = 100;
string s, tmp;
int main()
{
	int t;
	cin >> t;
	getchar();
	getline(cin, s);
	for(int i = 0; i < s.size(); i++)
	{
		if(s[i] >= '0' && s[i] <= '9')
			s[i] = ' ';
		s[i] = tolower(s[i]);
	}
	stringstream ss;
	ss << s;
	s = "";
	int cnt = 0;
	while(ss >> tmp)
	{
		if(tmp == "." || tmp == "," || tmp == "'")
		{
			if(tmp == "")
				s += tmp + " ";
			else
			{
				s.erase(s.size() - 1);
				s += tmp + " ";
			}
		}
		else
			s += tmp + " ";
	}
	if(s.back() == ' ')
		s.pop_back();
	//cout << s << endl;
	while(t --)
	{
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		int x = 0;
		while(1)
		{
			x = s.find(s1, x);
			if(x == -1)
				break;
			else
			{
				s.replace(x, s1.size(), s2);
			}
		}
		cout << s << endl;
	}
	return 0;
}

