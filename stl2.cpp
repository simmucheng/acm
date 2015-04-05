#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;
map<map<int,int>,int>q;
stack<int>ss;
int main()
{
    int i;
    ss.push(1);
    int tt=ss.top();
    ss.pop();
    int yy=ss.size();
    cout<<tt<<' '<<yy<<endl;

    return 0;
}
