#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double s[1200];
int dp[1200][2];
int main()
{
    int i,j,m,n;
    int ma;
    ma=-0xfffffff;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lf",&s[i]);
   for(i=1;i<=n;i++)
   {
       dp[i][0]=1;
       for(j=1;j<i;j++)
       {
           if(s[i]>s[j])
           dp[i][0]=max(dp[j][0]+1,dp[i][0]);
       }
   }
   for(i=n;i>=1;i--)
   {
       dp[i][1]=1;
       for(j=n;j>=i+1;j--)
       {
           if(s[i]>s[j])
           dp[i][1]=max(dp[j][1]+1,dp[i][1]);
       }
   }
    for(i=1;i<=n;i++)
        ma=max(dp[i][0]+dp[i][1]-1,ma);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            ma=max(dp[i][0]+dp[j][1],ma);
        }
    }
    printf("%d\n",n-ma);
    return 0;
}
