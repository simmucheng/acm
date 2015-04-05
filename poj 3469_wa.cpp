#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define inf INT_MAX>>1
using namespace std;
const int MAXN=20100;
struct node
{
    int value;
    int next;
    int xx;
};
vector<node>w[MAXN<<2];

int mark[MAXN<<2],m,n;
int step[MAXN<<2],q[MAXN<<2];

bool bfs(int nn)
{
    memset(mark,0,sizeof(mark));
    memset(step,0,sizeof(step));
    q[0]=nn;
    mark[nn]=1;
    int start=0,en=1;
    while(start<en)
    {
        int tt=q[start++];
        int len=w[tt].size();
        for(int ii=0;ii<len;ii++)
        {
            int son=w[tt][ii].next;
            if(!mark[son]&&w[tt][ii].value>0)
            {
                step[son]=step[tt]+1;
                mark[son]=1;
                q[en++]=son;
            }
        }
    }
    if(mark[2*m+1]==1)return true;
    return false;
}

int dinic(int nn,int get_min)
{
    if(nn==2*m+1)return get_min;
    int len=w[nn].size(),total=0;
    for(int ii=0;ii<len&&get_min-total>0;ii++)
    {
        int son=w[nn][ii].next;
        if(step[nn]!=step[son]-1||w[nn][ii].value<=0)continue;
        int left=dinic(son,min(get_min-total,w[nn][ii].value));
        if(left==0)step[son]=-1;
        else
        {
        total+=left;
        w[nn][ii].value-=left;
        int rr=w[nn][ii].xx;
        w[son][rr].value+=left;
        }
    }
    return total;
}
void addedge(int nn,int mm,int vv)
{
    node ee;
    ee.value=vv;
    ee.next=mm;
    ee.xx=w[mm].size();
    w[nn].push_back(ee);
    ee.value=0;
    ee.next=nn;
    ee.xx=w[nn].size()-1;
    w[mm].push_back(ee);
}
void init()
{
    for(int ii=0;ii<(MAXN<<2);ii++)
    w[ii].clear();
    return ;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        init();
        for(int ii=1;ii<=2*m;ii+=2)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            addedge(0,ii,x);
            addedge(ii+1,2*m+1,y);
            addedge(ii,ii+1,inf);
        }
        for(int ii=1;ii<=n;ii++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            addedge(x*2-1,y<<1,z);
            addedge(y*2-1,x<<1,z);
        }
        int uu=0;
        int ans=0;
        while(bfs(0))
            while(uu=dinic(0,inf))ans+=uu;
        printf("%d\n",ans);
    }
    return 0;
}
