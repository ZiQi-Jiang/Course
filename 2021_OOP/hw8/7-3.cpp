#include <iostream>
using namespace std;

class A {
public:
    A(int x = 0, int y = 0) : x(x), y(y) {}
    void show() const;
    A operator+(A& a);
    A operator-(A& a);
    int operator>(A&a);
private:
    int x, y;
};
A A::operator+(A& a){
	int x1=x+a.x;
	int y1=y+a.y;
    A b(x1,y1);
    return b;
}
A A::operator-(A& a){
	int x1=x-a.x;
	int y1=y-a.y;
    A b(x1,y1);
    return b;
}
int A::operator>(A& a){
    if(x*x+y*y>a.x*a.x+a.y*a.y){
        return 1;
    }
    else if(x*x+y*y==a.x*a.x+a.y*a.y){
        return 0;
    }
    else{
        return -1;
    }
}
void A::show() const {
    cout << "(" << x << ", " << y << ")" << endl;
}


int main() {
    int x,y;
    cin>>x>>y;
    A a1(x,y);
    cin>>x>>y;
    A a2(x,y);
    cout<<(a1>a2);
    return 0;
}