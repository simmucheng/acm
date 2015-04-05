#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#define N 10000000
using namespace std;
int dp[1001000];
struct node
{
    __int64 xx;
    __int64 yy;
}w[5010];
void init(int nn)
{
    for(int ii=0;ii<=nn;ii++)
    dp[ii]=N;
    return ;
}
__int64 get(__int64 aa,__int64 bb)
{
    return (__int64)sqrt(aa*aa*1.0-bb*bb*1.0);
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        scanf("%I64d%I64d",&w[i].xx,&w[i].yy);
        init(w[m].xx);
        dp[0]=0;
        int getmin=N;
        for(i=2;i<=m;i++)
        {
            int t2=w[i].xx-get(w[i].yy,w[i].yy-w[1].yy);
            t2=t2>0?t2:0;
            for(j=t2;j<w[i].xx;j++)
            {
                if(2*w[i].xx-j>=w[m].xx){getmin=min(getmin,dp[j]+1);continue;}
                dp[2*w[i].xx-j]=min(dp[j]+1 ,dp[2*w[i].xx-j]);
            }
        }
        if(getmin==N)
        printf("-1\n");
        else
        printf("%d\n",getmin);
    }
    return 0;
}
