#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double dp[510][20000];
int s[30];
int w[30];
int main()
{
    int i,j,m,n;
    int c;
    scanf("%d%d",&c,&m);
    for(i=0;i<c;i++)scanf("%d",&w[i]);
    for(i=0;i<m;i++)scanf("%d",&s[i]);
    for(i=0;i<c;i++)dp[0][w[i]*s[0]+10000]=1;
    for(i=1;i<m;i++)
    {
        for(int k=0;k<c;k++)
        {
           for(j=0;j<=20000;j++)
            {
                if(j-s[i]*w[k]<0)continue;
                if(dp[i-1][j-s[i]*w[k]]>0)
                {
                    dp[i][j]+=dp[i-1][j-s[i]*w[k]];
                }
            }
        }
    }
    printf("%.0f\n",dp[m-1][10000]);
    return 0;
}
