#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#define inf 1<<30
using namespace std;
const int MAXN=1100;
int num[MAXN],s[MAXN],mark[MAXN],visit[MAXN];
int m,n;
vector<int>w[MAXN];
void dfs(int nn)
{
    mark[nn]=1;
    int len=w[nn].size();
    if(len==0)num[nn]=s[nn];
    for(int ii=0;ii<len;ii++)
    {
        int son=w[nn][ii];
        if(!mark[son]){num[nn]=max(num[nn],s[son]);
        dfs(son);}
    }
    return ;
}
int get_dfs(int nn)
{
    int rr=1,sum=0,step=1;
    visit[m]=1;
    while(rr!=-1)
    {
        rr=-1;
        int get_max=-inf;
        for(int ii=1;ii<=nn;ii++)
        {
            if(visit[ii]&&!mark[ii]&&num[ii]+s[ii]>get_max)
            {
                get_max=num[ii]+s[ii];
                rr=ii;
            }
        }
        //cout<<"rr = "<<rr<<' '<<step<<' '<<s[rr]<<endl;
        if(rr==-1)break;
        mark[rr]=1;
        sum+=step*s[rr];
        step++;
        int len=w[rr].size();
        for(int ii=0;ii<len;ii++)
        {
            int son=w[rr][ii];
            if(!mark[son])visit[son]=1;
        }
    }
    return sum;
}
int main()
{
    while(scanf("%d%d",&n,&m),m||n)
    {
        memset(visit,0,sizeof(visit));
        memset(mark,0,sizeof(mark));
        memset(num,0,sizeof(num));
        for(int ii=1;ii<=n;ii++)w[ii].clear();
        for(int ii=1;ii<=n;ii++)
            scanf("%d",&s[ii]);
        for(int ii=1;ii<=n-1;ii++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            w[x].push_back(y);
        }
        dfs(m);
        memset(mark,0,sizeof(mark));
        int ans=get_dfs(n);
        printf("%d\n",ans);
    }
    return 0;
}
