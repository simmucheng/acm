#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int co;
    int ti;
}s[3100];
int dp[12000];
int cmp(node aa,node bb)
{
    if(bb.co*aa.ti!=aa.co*bb.ti)
    return bb.co*aa.ti<aa.co*bb.ti;
    return aa.ti<bb.ti;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        for(int ii=0;ii<m;ii++)
            scanf("%d%d",&s[ii].co,&s[ii].ti);
        sort(s,s+m,cmp);
        for(int ii=0;ii<m;ii++)
        {
            for(int jj=n;jj<=n-s[ii].ti;jj++)
            {
                dp[jj]=max(dp[jj+s[ii].ti]+(jj+s[ii].ti)*s[ii].co,dp[jj]);
                cout<<ii<<' '<<jj<<' '<<dp[jj]<<endl;
            }
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
