#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int v;
    int w;
}s[1010];
 int ro;
 int m;
int dp[1010][1010];
/*void init()
{
    for(int i=0;i<m;i++)
    for(int j=0;j<=ro;j++)
    dp[i][j]=0;
}*/
int main()
{
    int i,j,n;
    cin>>n;
    while(n--)
    {
        memset(dp,0,sizeof(dp));
        cin>>m>>ro;
        for(i=0;i<m;i++)
        cin>>s[i].v;
        for(i=0;i<m;i++)
        cin>>s[i].w;
        int mi=0;
        for(i=s[0].w;i<=ro;i++)
        dp[0][i]=s[0].v;
        for(i=1;i<m;i++)
        {
            for(j=0;j<=ro;j++)
            {
                if((dp[i-1][j]>dp[i-1][j-s[i].w]+s[i].v)||j<s[i].w)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j-s[i].w]+s[i].v;
                mi=max(mi,dp[i][j]);
            }
        }
        cout<<mi<<endl;
    }
    return 0;
}
