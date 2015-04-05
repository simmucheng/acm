#include<iostream>
#include<cstdio>
#include<algorithm>
#define INF 0xfffffff
using namespace std;
struct node
{
    int num;
    int price;
}s[110];
int dp[110][110];
int mm,n,m;
void init()
{
    for(int ii=0;ii<m;ii++)
    for(int jj=0;jj<m;jj++)
    dp[ii][jj]=INF;
}
int main()
{
    int i,j;
    scanf("%d",&n);
    while(n--)
    {
        int sum=0;
        //mm=0;
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
                scanf("%d%d",&s[i].num,&s[i].price);
                //mm+=s[i].num;
        }
        init();
        for(i=0;i<m;i++)
            dp[0][i]=s[i].price*(s[0].num+10);
        for(i=1;i<m;i++)
        {
            for(j=i;j<m;j++)
            {
                for(int k=i-1;k<=j;k++)
                {
                  if(k==j)
                  dp[i][j]=min(dp[i-1][k]+s[i].num*s[j].price,dp[i][j]);
                  else
                  dp[i][j]=min(dp[i-1][k]+(s[i].num+10)*s[j].price,dp[i][j]);

                }
                //cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
            }
        }
        printf("%d\n",dp[m-1][m-1]);
    }
    return 0;
}
