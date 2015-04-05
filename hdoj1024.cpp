#include<iostream>
#include<cstdio>
using namespace std;
int s[100010];
int dp[10][100010];
int sum(int x,int y)
{
    int si=0;
    int l;
    for(l=x;l<=y;l++)
    si+=s[l];
    return si;
}
int main()
{
    int i,j,m,n,k;
    int ci,num;
    while(scanf("%d%d",&ci,&num)!=EOF)
    {
        for(i=1;i<=num;i++)
        scanf("%d",&s[i]);
        for(i=1;i<=ci;i++)
        {
            for(j=1;j<=num;j++)
            {
                int mi=0;
                for(k=i-1;k<j;k++)
                    mi=max(mi,dp[i-1][k]+sum(k+1,j));
                dp[i][j]=mi;
            }
        }
        cout<<dp[ci][num]<<endl;
    }
    return 0;
}
