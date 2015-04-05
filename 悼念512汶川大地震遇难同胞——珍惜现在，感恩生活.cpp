#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
  int price;
  int wei;
  int number;
}s[110];
int main()
{
    int i,j,m,n,k,l,num;
    int money;
    int dp[110][110];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&money,&num);
        for(i=1;i<=num;i++)
        scanf("%d%d%d",&s[i].price,&s[i].wei,&s[i].number);
        memset(dp,0,sizeof(dp));
        for(i=1;i<=num;i++)
        {
            for(j=0;j<=money;j++)
            {
                int mi=0;
                for(k=0;j-k*s[i].price>=0&&k<=s[i].number;k++)
                {
                    mi=max(mi,dp[i-1][j-k*s[i].price]+k*s[i].wei);
                }
                dp[i][j]=mi;
            }
        }
        int ma=0;
        for(j=0;j<=money;j++)
        ma=max(ma,dp[num][j]);
        cout<<ma<<endl;
    }
    return 0;
}
