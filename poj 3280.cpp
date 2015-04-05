#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 0xfffffff
using namespace std;
char s[2010];
int dp[2010][2010];
struct node
{
    int dele;
    int add;
}w[30];
void init(int nn)
{
    for(int ii=0;ii<=nn+1;ii++)
        for(int jj=0;jj<=nn+1;jj++)
        dp[ii][jj]=0;
}
int main()
{
    int a,b,i,j,m,n;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        init(b);
        scanf("%s",s+1);
        while(a--)
        {
            char ee[2];
            scanf("%s",ee);
            scanf("%d%d",&w[ee[0]-'a'].add,&w[ee[0]-'a'].dele);
        }
        for(i=b;i>=1;i--)
            dp[0][i]=min(dp[0][i+1]+w[s[i]-'a'].dele,dp[0][i+1]+w[s[i]-'a'].add);
        for(i=1;i<=b;i++)
            dp[i][b+1]=min(dp[i-1][b+1]+w[s[i]-'a'].dele,dp[i-1][b+1]+w[s[i]-'a'].add);
        for(i=1;i<=b;i++)
        {
            for(j=b;j>=i;j--)
            {
                dp[i][j]=min(dp[i][j+1]+w[s[j]-'a'].dele,dp[i][j+1]+w[s[j]-'a'].add);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+w[s[i]-'a'].add);
                dp[i][j]=min(dp[i][j],dp[i-1][j]+w[s[i]-'a'].dele);
                if(s[i]==s[j])dp[i][j]=min(dp[i-1][j+1],dp[i][j]);
            }
        }
        int ma=N;
        for(i=0;i<b;i++)
        {
            ma=min(ma,dp[i][i+2]);
            ma=min(ma,dp[i][i+1]);
        }
        printf("%d\n",ma);
    }
    return 0;
}
