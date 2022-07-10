/* 7-6 队列操作 (10 分) */

#include<iostream>
#include<queue>
using namespace std;
queue <int> Q;
int main()
{
    int n;
    cin >> n;
    int op;
    for(int i = 1; i<=n; i++)
    {
        cin >> op;
        switch(op)
        {
            case 3: cout<< Q.size()<<endl;break;
            case 2:
                if(Q.empty()) cout<<"Invalid"<<endl;
                else
                {
                    int x = Q.front();
                    cout<<x<<endl;
                    Q.pop();
                }
                break;
            case 1:
                int x;
                cin >> x;
                Q.push(x);
                break;

        }

    }

}