#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
map<int,map<int,int> >dp;
int stone[50010];
int sum(int x,int y)
{
    int l;
    int w=0;
    for(l=x;l<=y;l++)
    w+=stone[l];
    return w;
}
int main()
{
    int n,i,j,k,m;

    while(scanf("%d",&n)!=EOF)
    {
        //memset(dp,0,sizeof(dp));
        int mi=0xfffffff;
        for(i=0;i<n;i++)
        scanf("%d",&stone[i]);
        for(i=0;i<n-1;i++)
        dp[i][i+1]=stone[i]+stone[i+1];
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                int ma=0xfffffff;
                for(k=i;k<j;k++)
                    ma=min(ma,dp[i][k]+dp[k+1][j]+sum(i,j));
                    //cout<<dp[i][k]<<' '<<dp[k+1][j]<<' '<<i<<' '<<j<<endl;
                dp[i][j]=ma;
                //cout<<ma<<' '<<i<<' '<<j<<endl;;
            }
            //mi=min(mi,dp[i][j]);
                   // cout<<mi<<endl;
        }
        cout<<dp[0][n-1]<<endl;
    }
    return 0;
}
