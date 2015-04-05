#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char s[110];
char w[110];
int dp[120][120];
int r[5][5]={
             5,-1,-2,-1,-3,
             -1,5,-3,-2,-4,
             -2,-3,5,-2,-2,
             -1,-2,-2,5,-1,
             -3,-4,-2,-1,-0xfffffff
             };
int change(char e)
{
    if(e=='A')return 0;
    else if(e=='C')return 1;
    else if(e=='G')return 2;
    else if(e=='T')return 3;
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        //memset(dp,0,sizeof(dp));
        int s1,w1;
        scanf("%d",&s1);
        scanf("%s",s+1);
        scanf("%d",&w1);
        scanf("%s",w+1);
        for(i=1;i<=w1;i++)
        dp[0][i]=dp[0][i-1]+r[4][change(w[i])];
        for(i=1;i<=s1;i++)
        dp[i][0]=dp[i-1][0]+r[change(s[i])][4];
        for(i=1;i<=s1;i++)
            for(j=1;j<=w1;j++)
                dp[i][j]=max(dp[i-1][j-1]+r[change(s[i])][change(w[j])],max(dp[i-1][j]+r[change(s[i])][4],dp[i][j-1]+r[4][change(w[j])]));
        printf("%d\n",dp[s1][w1]);
    }
    return 0;
}
