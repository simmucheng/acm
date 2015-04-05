#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[500100];
int u[500100];
int main()
{
    int i,j,m,n,tem;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(i=1;i<=m;i++)
        {
            scanf("%d",&u[i]);
        }
        for(i=1;i<=m;i++)
        {
            dp[i]=dp[i-1]+u[i]*u[i]+n;
            tem=u[i];
            for(j=i-1;j>=1;j--)
            {
                if(tem*u[j]*2<n)
                {
                    tem+=u[j];
                    if(dp[i]>(dp[j-1]+tem*tem+n)) dp[i]=(dp[j-1]+tem*tem+n);
                }
                else break;
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
