#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
int begin;
int end;
int distence;
int many
}s[1005];
bool cmp1(node x,node y)
{
    return x.distence<y.distence;
}
struct cmp(node &a,node &b)
{
    return a>b;
}
int main()
{
    priority_queue<int ,vector<int>,cmp>Queue;
    int group,i,j,k,flight,max;
    while(cin>>group>>flight>>max)
    {
        for(i=0;i<group;i++)
        {
            cin>>s[i].begin>>s[i].end>>s[i].many;
            s[i].distence=s[i].end-s[i].begin;
        }
       sort(s,s+group,cmp1);
       for(i=0;i<group;i++)
       {
           Queue.push(s[i].end);

       }

    }
}
