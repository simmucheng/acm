#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
struct node
{
    int num;
    int sta;
}s[220];
node dp[62][60*1100];
int cmp(node a,node b)
{
    return a.num<b.num;
}
int mark[220];
void init(int nn)
{
    memset(dp,0,sizeof(dp));
    memset(mark,0,sizeof(mark));
    return ;
}
int main()
{
    int i,j,m,n;
    int uu=0;
    scanf("%d",&n);
    init(n);
    for(i=0;i<3*n;i++)
    {
            scanf("%d",&s[i].num);
            s[i].sta=i;
    }
    sort(s,s+3*n,cmp);
    for(i=0;i<n;i++)
        printf("%d\n",s[i].sta+1);
    int sum=0;
    for(i=n;i<3*n;i++)
        sum+=s[i].num;
    for(i=n;i<3*n;i++)
    {
        dp[0][s[i].num].num=s[i].num;
        dp[0][s[i].num].sta=i;
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<=sum;j++)
        {
            for(int k=n;k<3*n;k++)
            {
                if(j-s[k].num<0)break;
                if(dp[i][j].num<=dp[i-1][j-s[k].num].num+s[k].num)
                {
                    dp[i][j].num=dp[i-1][j-s[k].num].num+s[k].num;
                    dp[i][j].sta=k;
                }
            }
        }
    }
    for(i=500*n+1;i<=1000*n;i++)
    {
        if(dp[n-1][i].num==i)
        {
            int ss=i;
            int cc=n-1;
            int tt=dp[n-1][i].sta;
            while(cc>=0)
            {
                mark[dp[cc][ss].sta]=1;
                printf("%d\n",s[dp[cc][ss].sta].sta+1);
                ss-=s[tt].num;
                cc--;
            }
            break;
        }
    }
    for(i=n;i<3*n;i++)
        if(!mark[i])
        printf("%d\n",s[i].sta+1);
    return 0;
}
