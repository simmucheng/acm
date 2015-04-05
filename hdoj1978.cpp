#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[110][110];
int s[110][110];
int main()
{
    int i,j,m,n,k,l;
    int x,y;
    int x1,y1;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&y);
        for(i=1;i<=x;i++)
        for(j=1;j<=y;j++)
        scanf("%d",&s[i][j]);
        memset(dp,0,sizeof(dp));
        dp[1][1]=1;
        for(i=1;i<=x;i++)
        {
            if(i>20)x1=i-20;
            else x1=1;
            for(j=1;j<=y;j++)
            {
                if(j>20)y1=j-20;
                else y1=1;
                for(k=x1;k<=i;k++)
                {
                    for(l=y1;l<=j;l++)
                    {
                        if(k==i&&l==j)continue;
                        if(s[k][l]>=(i+j-k-l))
                        {
                          dp[i][j]=(dp[i][j]+dp[k][l])%10000;
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[x][y]%10000);
    }
    return 0;
}
