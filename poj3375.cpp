#include<iostream>
#include<algorithm>
#define N 5000000000
__int64 dp[2100][100100];
using namespace std;
int main()
{
    int i,j,m,n;
    int s[100100];
    int w[2100];
    int mark[2100];
    while(cin>>m>>n)
    {
        for(i=1;i<=m;i++)
        cin>>s[i];
        for(j=1;j<=n;j++)
        cin>>w[j];
        sort(s+1,s+m+1);
        sort(w+1,w+n+1);
        __int64 r1=N;
        for(i=1;i<=m;i++)
        {
            dp[1][i]=abs(s[i]-w[1]);
            r1=min(r1,dp[1][i]);
        }
        __int64 r=N;
        mark[1]=1;
        if(n>1)
        {
            for(i=2;i<=n;i++)
             {
               mark[i]=0xfffffff;
               for(j=i;j<=m;j++)
                {
                  if(j==i)dp[i][j-1]=N;
                  if(dp[i-1][j-1]+abs(w[i]-s[j])<dp[i][j-1])
                  {
                    dp[i][j]=dp[i-1][j-1]+abs(w[i]-s[j]);
                    mark[i]=min(j,mark[i]);
                  }
                else {dp[i][j]=dp[i][j-1];mark[i]=mark[i-1];}
                if(i==n)r=min(r,dp[i][j]);
               }
             }
        }
        else r=r1;
        //cout<<r<<endl;
        cout<<dp[n][m]<<endl;
    }
    return 0;
}
