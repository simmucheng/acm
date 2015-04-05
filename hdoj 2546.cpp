#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int s[1200];
int dp[1200][2];
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
        scanf("%d",&s[i]);
        scanf("%d",&m);
        if(m<5){printf("%d\n",m);continue;}
        dp[0][0]=m;
        dp[0][1]=m;
        sort(s,s+n);
        for(i=1;i<=n;i++)
        {
            if(dp[i-1][0]-s[i]<5)
            {
                dp[i][1]=min(dp[i-1][1],dp[i-1][0]-s[i]);
                dp[i][0]=dp[i-1][0];
            }
            else
            {
                dp[i][0]=dp[i-1][0]-s[i];
                dp[i][1]=min(dp[i-1][1],dp[i][0]);
            }
        }
        printf("%d\n",dp[n][1]);
    }
    return 0;
}
