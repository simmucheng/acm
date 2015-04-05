#include<cstring>
#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<stack>
#define inf 1e9
using namespace std;

const int MAXN=31000;
struct node
{
    int num;
    int son;
};
vector<node>w[MAXN];

int mark[MAXN];
int path[MAXN];

int spfa(int nn)
{
    for(int ii=1;ii<=MAXN;ii++)path[ii]=inf;
    int sum=0;
    stack<int>q;
    q.push(nn);
    mark[nn]=1;
    path[nn]=0;
    while(!q.empty())
    {
        int ee=q.top();
        q.pop();
        mark[ee]=0;
        int len=w[ee].size();
        for(int ii=0;ii<len;ii++)
        {
            int so=w[ee][ii].son;
            int va=w[ee][ii].num;
            if(path[ee]+va<path[so])
            {
                path[so]=path[ee]+va;
                if(!mark[so]){q.push(so);mark[so]=1;}
            }
        }
    }
    return path[1];
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(int ii=1;ii<=m;ii++){w[ii].clear();mark[ii]=0;}
        for(int ii=1;ii<=n;ii++)
        {
            int x;
            node tt;
            scanf("%d%d%d",&tt.son,&x,&tt.num);
            w[x].push_back(tt);
        }
        int ans=spfa(m);
        printf("%d\n",ans);
    }
    return 0;
}

