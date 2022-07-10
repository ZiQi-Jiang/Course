#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct stu {
	string s;
	int id;
};

bool cmp(stu a,stu b) {
	if(a.s.length()==b.s.length()) return a.id>b.id;
	else return a.s.length()<b.s.length();
}
int main() {
	int n;
	string s;
	vector<stu> v;
	while(cin>>n) { //(cin >> n)!=EOF
		getchar();
		while(n--) {
			getline(cin,s);
			if(s=="stop") break;
			stu t;
			t.id=n;
			t.s=s;
			v.push_back(t);
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=0; i<v.size(); i++) {
			cout<<v[i].s<<endl;
		}
		v.clear();
	}
	return 0;
}
