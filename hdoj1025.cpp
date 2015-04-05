#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int s[500010];
int dp[500010];
int binary_search(int h,int k)
{
    int be=1;
    int len=k;
    int mia;
    while(be<=len)
    {
        mia=(be+len)/2;
        if(dp[mia]<=h)be=mia+1;
        else len=mia-1;
    }
    return be;
}
int main()
{
    int i,j,m,n,mu;
    mu=0;
    while(cin>>n)
    {
        ++mu;
        int u,v,k;
        for(i=1;i<=n;i++)
        {
           dp[i]=0;
           scanf("%d%d",&u,&v);
           s[u]=v;
        }
        dp[1]=s[1];
        k=1;
        for(i=2;i<=n;i++)
        {
            if(dp[k]<=s[i])dp[++k]=s[i];
            else
            {
                int a=binary_search(s[i],k);
                dp[a]=s[i];
            }
        }
        printf("Case %d:\n",mu);
        if(k>1)
        printf("My king, at most %d roads can be built.\n\n",k);
        else
        printf("My king, at most %d road can be built.\n\n",k);
    }
    return 0;
}
