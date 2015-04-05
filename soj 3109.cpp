#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int q[MAXN],mark[MAXN],step[MAXN];
int S,T;
struct node
{
    int next;
    int value;
    int xx;
}w[120];
bool bfs(int nn)
{
    memset(mark,0,sizeof(mark));
    int start=0,en=1;
    mark[S]=1;
    q[0]=S;
    while(start<en)
    {
        int tt=q[start++];
        int len=w[tt].size();
        for(int ii=0;ii<len;ii++)
        {
            int son=w[tt][ii].next;
            if(mark[son]||w[tt][ii].value<=0)continue;
            q[en++]=son;
            mark[son]=1;
            step[son]=step[tt]+1;
        }
    }
    if(mark[T]==1)return true;
    return false;
}
int dinic(int nn,get_min)
{
    if(nn==T)return get_min;
    int total=0;
    int len=w[nn].size();
    for(int ii=0;ii<len&&get_min-total>0;ii++)
    {
        int son=w[nn][ii].next;
        int left=dinic(w[nn][ii].next,min(get_min-total,w[nn][ii].value));
        if(left==0)step[son]=-1;
        total+=left;
        w[nn][ii].value-=left;
        +=left;
    }
    return total;
}
void addedge(int nn,int mm,int value)
{
    node ee;
    ee.next=mm;
    ee.value=value;
    ee.xx=w[mm].size();
    w[nn].push_back(ee);
    ee.next=nn;
    ee.xx=w[nn].size()-1;
    w[mm].push_back(ee);
}
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int ss=0;
        S=0;
        T=n+m+1;
        for(int ii=1;ii<=n;ii++)
        {
           gets(s);
           trans(ii,s);
        }
        for(int ii=1;ii<=m;ii++)
        {
            int x;
            scanf("%d",&x);
            w[S].push_back(ii+n);
        }
        int uu=0;
        while(bfs(0))
            while(uu=dinic(0,INF))ans+=uu;
        printf("%d\n",ss-ans);
    }
    return 0;
}
