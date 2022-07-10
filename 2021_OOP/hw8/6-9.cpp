#include <iostream>
using namespace std;
class MyTime
{
public:
	MyTime(int h = 0, int m = 0, int s = 0) :h(h), m(m), s(s){}
	friend istream& operator>>(istream&, MyTime&);
	friend ostream& operator<<(ostream&, MyTime&);
	MyTime operator++();
private:
	int h, m, s;
};
istream& operator>>(istream& is, MyTime& t){
	is >> t.h >> t.m >> t.s;
	return is;
}
ostream& operator<<(ostream& os, MyTime& t) {
	os << t.h << ":" << t.m << ":" << t.s;
	return os;
}
MyTime MyTime::operator++() {
	s += 1;
	if (s == 60) {
		s = 0;
		m += 1;
		if (m == 60) {
			m = 0;
			h += 1;
			if (h == 24)h = 0;
		}
	}
	return MyTime(h, m, s);
}


/* 请在这里填写答案 */

