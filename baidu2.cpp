#include<iostream>
#include<cstdio>
using namespace std;
__int64 hai(int x)
{
    int y;
    __int64 nu=1;
    y=(2+(x/2))*(x/2-1)*2;
    for(int l=1;l<=x*x-y;l++)
    nu=nu*2%2012;
    return nu;
}
int main()
{
    int i,j,n;
    __int64 m;
    __int64 dp[510][2];
    dp[1][0]=1;
    dp[1][1]=1;
    for(i=2;i<=n;i++)
             {
                 dp[i][0]=dp[i-1][0]+dp[i-1][1];
                 dp[i][1]=dp[i-1][0];
             }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==2)printf("16\n");
        else
        {
           // cout<<dp[3][1]+dp[3][0]<<endl;
             m=hai(n);
             for(i=2;i<=n/2;i++)
             m=m*((dp[i][0]+dp[i][1])%2012)*((dp[i][0]+dp[i][1])%2012)*((dp[i][0]+dp[i][1])%2012)*((dp[i][0]+dp[i][1])%2012)%2012;
             printf("%I64d\n",m%2012);
        }
    }
    return 0;
}
