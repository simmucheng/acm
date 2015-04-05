#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tree,num;
int s[110][110];
struct node
{
 int re;
 int le;
 int vir;
}f[110];
int k;
int p[110];
int dp[110][110];
void dfs(int root)
{
    if(k>tree)return ;
    k++;
    int i;
    for(i=1;i<=tree;i++)
    {
        if(s[root][i]>=0&&(p[i]<0||p[root]<0))
        {
             p[i]=1;
             p[root]=1;
             if(f[root].re==0)
             f[root].re=i;
             else f[root].le=i;
             f[i].vir=s[root][i];
            // cout<<root<<' '<<i<<endl;
             dfs(i);
        }
    }
}
int DP(int w1,int ti)
{
  // cout<<"w1="<<w1<<endl;
    //cout<<"le="<<f[w1].le;
    //cout<<"re="<<f[w1].re;
    //cout<<"w1="<<w1<<endl;
    if(ti==0||w1==0)return 0;
    if(dp[w1][ti]!=-1)return dp[w1][ti];
    int k;
    for(k=0;k<ti;k++)
    {
       int le=DP(f[w1].le,k);
       int re=DP(f[w1].re,ti-k-1);
       //cout<<re+le<<' '<<"k="<<k<<"w1="<<w1<<endl;
       if(dp[w1][ti]<le+re)
       dp[w1][ti]=le+re;
    }
    dp[w1][ti]+=f[w1].vir;
   // cout<<dp[w1][ti]<<' '<<w1<<' '<<ti<<endl;
    return dp[w1][ti];
}
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&tree,&num)!=EOF)
    {
        k=0;
        memset(f,0,sizeof(f));
        memset(s,-1,sizeof(s));
        memset(p,-1,sizeof(p));
        memset(dp,-1,sizeof(dp));
        for(i=0;i<tree-1;i++)
        {
          int x,y,app;
          scanf("%d%d%d",&x,&y,&app);
          s[x][y]=s[y][x]=app;
        }
        dfs(1);
        int t=DP(1,++num);
        printf("%d\n",t);
    }
    return 0;
}
