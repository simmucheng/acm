#include<iostream>
#include<cstdio>
#include<cstring>
#define N 0xfffffff
using namespace std;
int next[240][240];
int mark[240];
int bb;
int dp[240][240];
void  dfs(int aa)
{
    for(int ii=1;ii<=next[aa][0];ii++)
    dfs(next[aa][ii]);
    dp[aa][1]=next[aa][0];
    for(int ii=1;ii<=next[aa][0];ii++)
    {
        for(int kk=bb-1;kk>=1;kk--)
        {
            if(dp[aa][kk]<N)
            for(int jj=1;jj<=bb-1;jj++)
            if(dp[next[aa][ii]][jj]<N)
            {
            dp[aa][jj+kk]=min(dp[aa][jj+kk],dp[next[aa][ii]][jj]+dp[aa][kk]-1);
            //cout<<"aa = "<<aa<<' '<<"son = "<<next[aa][ii]<<' '<<"many = "<<jj+kk<<' '<<dp[aa][jj+kk]<<endl;
            }
        }
    }
    return ;
}
int DP(int aa,int nn)
{
    dfs(aa);
    int getmin=N;
    for(int ii=1;ii<=nn;ii++)
    {
        if(ii==aa)continue;
        getmin=min(getmin,dp[ii][bb]+1);
    }
    getmin=min(getmin,dp[aa][bb]);
    return getmin;
}
void init(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        for(int jj=0;jj<=nn;jj++)
        dp[ii][jj]=N;
        next[ii][0]=0;
    }
    return ;
}
int main()
{
    int i,j,m,n;
    int a,b;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        bb=n;
        memset(mark,0,sizeof(mark));
        init(m);
        for(i=1;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            next[a][++next[a][0]]=b;
            mark[b]=1;
        }
        int temp;
        for(i=1;i<=m;i++)
        {
            if(!mark[i])
            {
                temp=DP(i,m);
                break;
            }
        }
        printf("%d\n",temp);
    }
    return 0;
}
