#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct node
{
int pois;
int dis;
};
struct cmp
{
    bool operator() (node a,node b){
    if(a.pois!=b.pois)return a.pois>b.pois;
    else return a.dis>b.dis;}
};
int main()
{
    priority_queue<node ,vector<node>,cmp>Queue;
    int cas,n,result;
    node t;
    int flse;
    cin>>cas;
    while(cas--)
    {
        cin>>n;
        while(n--)
        {
            cin>>t.pois>>t.dis;
            Queue.push(t);
        }
        flse=true;
        while(!Queue.empty())
        {
            if(flse==true)
            {
                flse=false;
                t=Queue.top();
                Queue.pop();
                t.pois+=t.dis;
                Queue.push(t);
            }
            else {
                flse=true;
                Queue.pop();
                result=t.pois;
                }
        }
        cout<<result<<endl;
    }
    return 0;
}
