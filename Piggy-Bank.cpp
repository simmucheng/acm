#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int money;
    int wei;
}s[510];
int dp[10010];
int main()
{
    int i,j,m,n,k,l,N;
    int empty,full;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&empty,&full);
        for(j=0;j<=full-empty;j++)
        dp[j]=0xfffffff;
        scanf("%d",&N);
        for(i=0;i<N;i++)
        scanf("%d%d",&s[i].money,&s[i].wei);
        for(k=0;k*s[0].wei<=full-empty;k++)
        dp[k*s[0].wei]=k*s[0].money;
        for(i=1;i<N;i++)
        {
            for(j=s[i].wei;j<=full-empty;j++)
            {
                dp[j]=(dp[j-s[i].wei]+s[i].money)<dp[j]?(dp[j-s[i].wei]+s[i].money):dp[j];
            }
        }
        if(dp[full-empty]<0xfffffff)
        printf("The minimum amount of money in the piggy-bank is %d.\n",dp[full-empty]);
        else printf("This is impossible.\n");
    }
    return 0;
}
