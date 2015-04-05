#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int s[1010];
    int dp[1010];
    int i,j,m,n;
    cin>>n;
    for(i=0;i<n;i++)
    scanf("%d",&s[i]);
    dp[0]=1;
    int num=dp[0];
    for(i=1;i<n;i++)
    {
        dp[i]=1;
        for(j=0;j<i;j++)
        {
            if(s[i]>s[j])
            dp[i]=max(dp[j]+1,dp[i]);
        }
        num=max(dp[i],num);
    }
    printf("%d\n",num);
    return 0;
}
