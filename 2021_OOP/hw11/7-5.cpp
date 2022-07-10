#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
using namespace std;
class student{
	public:
		string id, name;
		map<string, double> course;
		student() : id(""), name("") {
			course.clear();
		}
		void set1(string id_, string name_) {
			id = id_;
			name = name_;
		}
		void set2(string a, double b) {
			course[a] = b;
		}
		bool operator < (const student& tmp) const {
			return id < tmp.id;
		}
};
int main() {
	string in;
	set<string> s;
	vector<student> res;
	map<string, int> mp;
	while (getline(cin, in)) {
		int n = 0;
		for (int i = 0; i < in.size(); i++) {
			if (in[i] == ',') {
				n++;
			}
		}
		switch (n) {
			case 1: {
				int ad = -1;
				for (int i = 0; i < in.size(); i++) {
					if (in[i] == ',') {
						ad = i;
						break;
					}
				}
				string id, name;
				id = in.substr(0, ad);
				name = in.substr(ad+2);
				if (!mp.count(id)) {
					mp[id] = res.size();
					student tmp;
					tmp.set1(id, name);
					res.push_back(tmp);
				} else {
					ad = mp[id];
					res[ad].set1(id, name);
				}
				break;
			}
			case 2: {
				int ad1 = -1, ad2 = -1;
				for (int i = 0; i < in.size(); i++) {
					if (in[i] == ',') {
						if (ad1 == -1) {
							ad1 = i;
						} else {
							ad2 = i;
							break;
						}
					}
				}
				string id, course, grade;
				id = in.substr(0, ad1);
				course = in.substr(ad1+2, ad2-ad1-2);
				grade = in.substr(ad2+2);
				s.insert(course);
				if (!mp.count(id)) {
					mp[id] = res.size();
					student tmp;
					tmp.set2(course, atof(grade.c_str()));
					res.push_back(tmp);
				} else {
					int ad = mp[id];
					res[ad].set2(course, atof(grade.c_str()));
				}
				break;
			}
		}
	}
	cout << "student id, name";
	for (auto i: s) {
		cout << ", " << i;
	}
	cout << ", average" << endl;
	vector<double> sum(s.size(), 0), cnt(s.size(), 0);
	sort(res.begin(), res.end());
	int tot = 0;
	double ave = 0;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].id << ", "<< res[i].name;
		int ad = 0;
		tot = 0;
		ave = 0;
		for (auto j: s) {
			cout << ", ";
			if (res[i].course.count(j)) {
				cout << fixed << setprecision(1) << res[i].course[j];
				sum[ad] += res[i].course[j];
				cnt[ad]++;
				ave += res[i].course[j];
				tot++;
			}
			ad++;
		}
		cout << ", " << fixed << setprecision(1) << ave/tot << endl;
	}
	cout << ", ";
	tot = 0;
	ave = 0;
	for (int i = 0; i < sum.size(); i++) {
		tot++;
		ave += sum[i]/cnt[i];
		cout << ", " << fixed << setprecision(1) << sum[i]/cnt[i];
	}
	cout << ", " << fixed << setprecision(1) << ave/tot << endl;
	return 0;
}