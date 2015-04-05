#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*struct cmp{
bool operator()(__int64 &a,__int64 &b)
{
    return a>b;
}
};*/
int main()
{
    int n,i;
    int m;
    while(cin>>n)
    {
        __int64 min=0;
    priority_queue<__int64,vector<__int64>,greater<__int64> >Queue;
    for(i=0;i<n;i++)
    {
        cin>>m;
        Queue.push(m);
    }
    while(Queue.size()>1){
    __int64 x=Queue.top();Queue.pop();
    __int64 y=Queue.top();Queue.pop();
    min+=x+y;
    Queue.push(x+y);
                         }
    cout<<min<<endl;
    }
    return 0;
}
