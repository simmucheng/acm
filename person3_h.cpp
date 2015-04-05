#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int ss[50];
__int64 dp[50][3];
int get_num(__int64 nn)
{
    int len=0;
    while(nn)
    {
        ss[len++]=nn%10;
        nn/=10;
    }
    return len;
}
__int64 dfs(int len,int sta,int limit)
{
    if(len==-1&&sta==0)return 1;
    else if(len==-1)return 0;
    if(dp[len][sta]!=-1&&!limit)return dp[len][sta];
    int rr=(limit==0)?9:ss[len];
    int uu;
    __int64 tt=0;
    for(int ii=0;ii<=rr;ii++)
    {
        if(sta==0)uu=0;
        else if(ii==4)uu=1;
        else if(sta==1&&ii==9)uu=0;
        else uu=2;

        __int64 ans=dfs(len-1,uu,limit&&(ii==rr));
        tt+=ans;
    }
    return limit?tt:dp[len][sta]=tt;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        __int64 m;
        memset(dp,-1,sizeof(dp));
        scanf("%I64d",&m);
        int len=get_num(m);
        __int64 ans=dfs(len-1,2,1);
        printf("%I64d\n",ans);
    }
    return 0;
}
