#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    __int64 dp[40];
    while(cin>>n>>m,m||n)
    {
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i-j<1)continue;
                dp[i]+=dp[i-j];
            }
        }
        cout<<dp[n]<<endl;
    }
}
