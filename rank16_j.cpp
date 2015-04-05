#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#define inf 1<<30
using namespace std;
const int MAXN=101000;
struct node
{
    int cost;
    int next;
};
vector<node>w[MAXN];
vector<int>D[MAXN];
int mark[MAXN],path[MAXN],fa[MAXN],N,M,C;
struct cmp
{
    bool operator()(int aa,int bb)
    {
        return aa>bb;
    }
};
priority_queue<int,vector<int>,cmp>q;
int spfa(int nn)
{
    for(int ii=1;ii<=nn;ii++)path[ii]=inf;
    for(int ii=1;ii<=nn;ii++)mark[ii]=0;
    path[1]=0;
    while(!q.empty())q.pop();
    q.push(1);
    while(!q.empty())
    {
        int tt=q.top();
        q.pop();
        int len=w[tt].size();
        for(int ii=0;ii<len;ii++)
        {
            int son=w[tt][ii].next;
            if(path[tt]+w[tt][ii].cost<path[son])
            {
                path[son]=path[tt]+w[tt][ii].cost;
                if(!mark[son])q.push(son);
            }
        }
        if(fa[tt]+1<=nn&&fa[tt]+1>=1)
        {
           len=D[fa[tt]+1].size();
           for(int ii=0;ii<len;ii++)
           {
               int son=D[fa[tt]+1][ii];
               if(path[tt]+C<path[son])
               {
                   path[son]=path[tt]+C;
                   if(!mark[son])q.push(son);
               }
           }
        }
        if(fa[tt]-1<=nn&&fa[tt]-1>=1)
        {
           len=D[fa[tt]-1].size();
           for(int ii=0;ii<len;ii++)
           {
               int son=D[fa[tt]-1][ii];
               if(path[tt]+C<path[son])
               {
                   path[son]=path[tt]+C;
                   if(!mark[son])q.push(son);
               }
           }
        }
    }
    return path[nn];
}

int main()
{
    int n,sta=1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d%d",&N,&M,&C);
        for(int ii=1;ii<=N;ii++){w[ii].clear();D[ii].clear();}
        for(int ii=1;ii<=N;ii++)
        {
            int x;
            scanf("%d",&x);
            D[x].push_back(ii);
            fa[ii]=x;
        }
        for(int ii=1;ii<=M;ii++)
        {
            int x,y,cost;
            scanf("%d%d%d",&x,&y,&cost);
            node ee;
            ee.next=y;
            ee.cost=cost;
            w[x].push_back(ee);
            ee.next=x;
            w[y].push_back(ee);
        }
        int ans=spfa(N);
        if(ans>=inf){printf("-1\n");continue;}
        printf("Case #%d: %d\n",sta++,ans);
    }
}
