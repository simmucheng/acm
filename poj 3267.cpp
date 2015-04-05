#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
  int len;
  char v[30];
}s[610];
char w[310];
int dp[310];
int transform(int x,int y,int d)
{
    int r=0;
    int ee,rr;
    ee=x;
    rr=0;
    while(ee<=y)
    {
        if(w[ee]!=s[d].v[rr])r++;
        else rr++;
        ee++;
    }
    //int tt=strlen(s[d]);
    if(s[d].len==rr)return r;
    else return 0xffffff;
}
int cmp(node aa,node bb)
{
    return aa.len<bb.len;
}
void init()
{
    for(int k=0;k<300;k++)
    dp[k]=0xfffffff;
}
int main()
{
    int i,j,m,n,k,l;
    init();
    scanf("%d%d",&m,&n);
    scanf("%s",&w);
    for(i=0;i<m;i++)
    {
        scanf("%s",s[i].v);
        s[i].len=strlen(s[i].v);
    }
    sort(s,s+m,cmp);
    dp[0]=0;
    for(i=0;i<=n;i++)
    {
        dp[i]=i;
        for(k=0;k<i;k++)
        {
          dp[i]=min(dp[i],dp[k]+(i-k));
          for(j=0;j<m;j++)
          {
           if(w[k]==s[j].v[0]&&w[i-1]==s[j].v[s[j].len-1])
           {
           int t=s[j].len;
           if(i-t<k)break;
           int u=transform(k,i-1,j);
           dp[i]=min(dp[k]+u,dp[i]);
           }
          }
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}
