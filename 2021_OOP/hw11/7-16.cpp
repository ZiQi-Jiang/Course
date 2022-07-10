#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void div(string str, map<string, int>& mp) {
	string str0, str1;
	int front = 1;	// 记录化合物系数
	int back = 1;	// 元素后跟的个数

	for(int i = 0;i < str.size();) {
		str0.clear();	// 每次都需要做的准备工作
		str1.clear();
		back = 1;

		// 先取到系数
		while(i < str.size() && str[i] >= '0' && str[i] <= '9') {
			str0 += str[i];
			i ++;		
		}
		if(!str0.empty()) {
			front = stoi(str0);
			str0.clear();
		}
	
		// 取元素
		if(i < str.size() && str[i] >= 'A' && str[i] <= 'Z') {
			str0 += str[i];
			i ++;
			while(i < str.size() && str[i] >= 'a' && str[i] <= 'z') {
				str0 += str[i];
				i ++;
			} 
			// 到上面元素就取完了，然后下面取它后面跟的个数
			while(i < str.size() && str[i] >= '0' && str[i] <= '9') {
				str1 += str[i];
				i ++;	
			}
			if(!str1.empty()) {
				back = stoi(str1);
				str1.clear();
			}
		}

		// 这里元素和个数都取完了， 然后存入map
		mp[str0] += front * back;
	}
}

void get_elem(string str, map<string, int>& mp) {
	if(!str.find('+')) {
		div(str, mp);
	}		// 拿到了字符串， 如果没有'+'， 则直接将字符串传入div()。
	else {
		string temp;
		temp.clear();
		for(int i = 0;i < str.size();) {
			while(str[i] != '+' && i < str.size()) {	// 取到'+'或者字符串结尾 就结束
				temp += str[i];
				i ++;
			}
			div(temp, mp);	// 把化合物传入div()
			temp.clear();
			if(i != str.size())	// 这里是一个条件判断，如果取到加号，下标向后移一位。如果到了字符串结尾，再向后移就不合适了 所以做一个条件判断
				i ++;
		}
	}
}

bool match(const string& str) {
	int equal_pos = str.find('=');	// 找到 '=' 的位置，将其分为前后两个字符串
	string str_front = str.substr(0,equal_pos);
	string str_back = str.substr(equal_pos+1);
	
	map<string, int> mp1;	// 定义两个map容器，用来存储 (元素,个数)
	map<string, int> mp2;
	mp1.clear();
	mp2.clear();
	
	get_elem(str_front, mp1); // 该函数会解析前后字符串， 并更新map的存储
	get_elem(str_back, mp2);

	if(mp1 == mp2) return true;	// 判断两个map中元素与个数是否想等，若相等这说明守恒
	else return false;		//  如果还要判断化合物的化学式是否正确 = =那就麻烦了 还是就题论题
}

int main()
{
	int number;
	cin >> number;
	getchar();		// 吸收数字输入之后的空格
	while(number --) {
		string temp;
		getline(cin, temp);
		if(match(temp)) {	// match()函数 : 检查方程式是否正确
			cout << "Easy!" << endl;
		}
		else {
			cout << "Hard!" << endl;
		}
	}
	return 0;
}

