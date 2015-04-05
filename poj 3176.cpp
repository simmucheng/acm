#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int dp[400][400];
int s[400][400];
int main()
{
    int i,j,m,n;
    cin>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=i;j++)
    scanf("%d",&s[i][j]);
    for(i=1;i<=n;i++)dp[n][i]=s[n][i];
    int sum=dp[n][n];
    for(i=n-1;i>=1;i--)
    for(j=1;j<=i;j++)
    {
    dp[i][j]=max(dp[i+1][j],dp[i+1][j+1]);
    dp[i][j]+=s[i][j];
    sum=max(sum,dp[i][j]);
    }
    printf("%d\n",sum);
    return 0;
}
