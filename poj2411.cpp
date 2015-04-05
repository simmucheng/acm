#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
 __int64 dp[2][2<<11];
int i,j,m,n,t;
void dfs(int d,int mm)
{
    if(d==m)
    {
    dp[0][mm]++;return ;
    }
    if(d<=m-1)
     dfs(d+1,mm<<1);
    if(d<=m-2)
     dfs(d+2,mm<<2|3);
}
void DFS(int d,int nn,int mm)
{
    if(d==m)
    {
        dp[t][nn]+=dp[(t+1)%2][mm];
        return ;
    }
    if(d<=m-1)
    {
        DFS(d+1,nn<<1,mm<<1|1);
        DFS(d+1,nn<<1|1,mm<<1);
    }
    if(d<=m-2)
    DFS(d+2,nn<<2|3,mm<<2|3);
}
int main()
{
    while(scanf("%d%d",&m,&n),n||m)
    {
        memset(dp,0,sizeof(dp));
        if((m*n)%2){printf("0\n");continue;}
        if(n>m)
        {
            m^=n;
            n^=m;
            m^=n;
        }
        dfs(0,0);
        t=1;
        for(i=2;i<=n;i++)
        {
            t=(i+1)%2;
            DFS(0,0,0);
            memset(dp[(t+1)%2],0,sizeof(dp[0]));
        }
        printf("%I64d\n",dp[(n+1)%2][(1<<m)-1]);
    }
    return 0;
}
