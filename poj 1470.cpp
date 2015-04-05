#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int> q[1910];
int ques[1910][1910];
int nu[1910];
int ss[1910];
int r[1910];
int visit[1910];
int fa[1910];
int ancestor[1910];
int n;
int find_fa(int x)
{
    if(x!=fa[x])
    fa[x]=find_fa(fa[x]);
    return fa[x];
}
void init()
{
    for(int ii=0;ii<=n;ii++)
    {
        ancestor[ii]=0;
        q[ii].clear();
        visit[ii]=0;
        ss[ii]=0;
        r[ii]=1;
        fa[ii]=ii;
        nu[ii]=0;
        for(int jj=1;jj<=n;jj++)
        ques[ii][jj]=0;
    }
    return ;
}
int unit(int x1,int y1)
{
    int aa=find_fa(x1);
    int bb=find_fa(y1);
    if(aa==bb)return 0;
    if(r[aa]>=r[bb]){fa[bb]=aa;r[aa]+=r[bb];}
    else {fa[aa]=bb;r[aa]+=r[bb];}
    return 1;
}
void lca(int nn)
{
    ancestor[nn]=nn;
    int size=q[nn].size();
    for(int ii=0;ii<size;ii++)
    {
        lca(q[nn][ii]);
        unit(nn,q[nn][ii]);
        ancestor[find_fa(nn)]=nn;
    }
    visit[nn]=1;
    for(int ii=1;ii<=n;ii++)
    {
        if(ques[nn][ii]&&visit[ii])
        {
            ss[ancestor[find_fa(ii)]]+=ques[nn][ii];
            ques[nn][ii]=0;
            ques[ii][nn]=0;
        }
    }
    return ;
}
int main()
{
    int i,j,m;
    int a,b,c,d;
    char xx;
    while(scanf("%d",&n)!=EOF)
    {
     init();
     for(i=1;i<=n;i++)
     {
        int pp;
        scanf("%d:(%d)",&a,&pp);
        for(j=0;j<pp;j++)
        {
            scanf("%d",&b);
            q[a].push_back(b);
            nu[b]++;
        }
     }
     scanf("%d",&c);
     int v,w;
     while(c--)
     {
        char g;
        while(scanf("%c",&g)&&g!='(');
        scanf("%d%d",&v,&w);
        while(scanf("%c",&g)&&g!=')');
        ques[v][w]++;
        ques[w][v]++;
     }
     for(i=1;i<=n;i++)
     {
        if(nu[i]==0)
        {lca(i);break;}
     }
     for(i=1;i<=n;i++)
     {
        if(ss[i]>0)
        printf("%d:%d\n",i,ss[i]);
     }
    }
    return 0;
}
