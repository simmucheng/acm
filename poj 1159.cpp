#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
char w[5010];
short dp[5010][5010];
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    scanf("%s",(w+1));
    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        dp[i][n+1]=i;
        dp[0][i]=1+n-i;
        dp[i][0]=i;
    }
    for(i=1;i<=n;i++)
        for(j=n;j>=1;j--)
            {
                if(i>=j)break;
                if(w[i]==w[j])dp[i][j]=min((int)dp[i-1][j+1],min(dp[i-1][j]+1,dp[i][j+1]+1));
                else
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j+1]+1);
                //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            }
    int sum=0xfffffff;
    for(i=0;i<n;i++)
    { sum=min(sum,(int)dp[i][i+1]);
      sum=min(sum,(int)dp[i][i+2]);
    }
    printf("%d\n",sum);
    return 0;
}
