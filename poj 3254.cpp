#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
__int64 mark[20];
int s[1000];
int dp[20][1000];
int top;
int judge(int nn)
{
    if(nn&(nn<<1))return 0;
    return 1;
}
void init(int nn)
{
    for(int ii=0;ii<nn;ii++)
    {
        if(judge(ii))
        {
            s[++top]=ii;
        }
    }
    return ;
}
int main()
{
    int i,j,m,n,k;
    int a,b,e;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        memset(dp,0,sizeof(dp));
        top=0;
        init(1<<b);
        for(i=1;i<=a;i++)
        {
            for(j=1;j<=b;j++)
            {
                scanf("%d",&e);
                if(e==1)
                    mark[i]+=1<<(b-j);
            }
        }
        dp[0][0]=1;
        mark[0]=0;
        __int64 pp=1;
        for(i=1;i<=a+1;i++)
        {
            for(j=1;j<=top;j++)
            {
                if((mark[i]^((pp<<(b+1))-1))&s[j])continue;
                for(k=1;k<=top;k++)
                {
                    if(s[j]&s[k])continue;
                    dp[i][s[j]]=(dp[i][s[j]]+dp[i-1][s[k]])%100000000;
                }
               // cout<<dp[i][s[j]]<<i<<' '<<s[j]<<endl;
            }
        }
        printf("%d\n",dp[a+1][0]);
    }
    return 0;
}
