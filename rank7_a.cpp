#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
const double eps=1e-8;
const long long MAXN=1e12;
vector<int>w[3100];
long long q[3100][3100];
long long path[3100];
long long get_p[3100][3100],get_min;
int mark[3100];
int pre[3100];
long long prime(int nn)
{
    int rr=1;
    path[0]=0;
    long long ret=0;
    while(rr!=-1)
    {
        long long get_max=MAXN;
        rr=-1;
        for(int ii=0;ii<nn;ii++)
        {
            if(get_max>path[ii]&&!mark[ii])
            {
                get_max=path[ii];
                rr=ii;
            }
        }
        if(rr==-1)break;
        ret+=get_max;
        mark[rr]=1;
        int len=w[rr].size();
        for(int ii=0;ii<len;ii++)
        {
            int son=w[rr][ii];
            if(path[son]>q[rr][son]&&!mark[son])
                {
                    path[son]=q[rr][son];
                    pre[son]=rr;
                }
        }
    }
    return ret;
}
void get_ans(int nn)
{
    for(int ii=1;ii<nn;ii++)
    {
        w[ii].push_back(pre[ii]);
        w[pre[ii]].push_back(ii);
    }
    return ;
}
void init(int nn)
{
    for(int ii=0;ii<nn;ii++)
    {
        w[ii].clear();
        mark[ii]=0;
        path[ii]=MAXN;
    }
    for(int ii=0;ii<nn;ii++)
        for(int jj=0;jj<nn;jj++)
            {
                get_p[ii][jj]=MAXN;
                q[ii][jj]=MAXN;
            }
    return ;
}
long long dfs1(int nn,int ac,int fa,int ff)
{
    int len=w[ff].size();
    long long ans=q[nn][ff];//include the root
    for(int ii=0;ii<len;ii++)
    {
        int son=w[ff][ii];
        if(son==nn||son==fa||son==ac)continue;
        ans=min(ans,dfs1(nn,ac,ff,son));
    }
    return ans;
}

void dfs2(int nn,int ac,int fa,int mm)
{
    int len=w[nn].size();
    for(int ii=0;ii<len;ii++)
    {
        int son=w[nn][ii];
        if(son==mm||son==fa||son==ac)continue;
        get_min=min(get_min,dfs1(son,ac,nn,mm));
        dfs2(son,ac,nn,mm);
    }
    cout<<nn<<' '<<mm<<' '<<get_min<<endl;
    get_p[nn][mm]=get_p[mm][nn]=get_min;
    return ;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        double total=0;
        init(n);
        for(int ii=1;ii<=m;ii++)
        {
            int x,y,t;
            scanf("%d%d%d",&x,&y,&t);
            q[x][y]=q[y][x]=t;
            w[x].push_back(y);
            w[y].push_back(x);
        }
        long long ans=prime(n);
        for(int ii=0;ii<m;ii++)w[ii].clear();
        get_ans(n);
        for(int ii=0;ii<n;ii++)
        {
            int len=w[ii].size();
            for(int jj=0;jj<len;jj++)
            {
                int son=w[ii][jj];
                if(get_p[ii][son]!=MAXN)continue;
                long long hh=q[ii][son];
                q[ii][son]=q[son][ii]=MAXN;
                get_min=dfs1(ii,ii,son,son);
                q[ii][son]=q[son][ii]=hh;
                dfs2(ii,ii,ii,son);
                cout<<"ii = "<<ii<<' '<<"son = "<<son<<get_p[ii][son]<<endl;
            }
        }
        int num;
        scanf("%d",&num);
        for(int ii=1;ii<=num;ii++)
        {
            long long ss=ans;
            int x,y;
            long long t;
            scanf("%d%d%lld",&x,&y,&t);
            if(pre[x]==y||pre[y]==x)ss+=min(t,get_p[x][y])-q[x][y];
            cout<<get_p[x][y]<<endl;
            cout<<"ss = "<<ss<<endl;
            total+=ss;
        }
        double pp=total/num;
        printf("%.4f\n",pp+eps);
    }
    return 0;
}
