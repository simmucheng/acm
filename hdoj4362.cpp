#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[52][1005];
struct node
{
    int p;
    int e;
}s[52][1005];
int cmp(node x,node y)
{
    if(x.p!=y.p)
    return x.p<y.p;
}
int cost(int a1,int a2,int a3)
{
    return dp[a1-1][a2]+abs(s[a1][a3].p-s[a1-1][a2].p);
}
int Q[1005];
int main()
{
    int i,j,m,n,local,k,t;
    int len,wei,many,top,tail;
    scanf("%d",&many);
    while(many--)
    {
        scanf("%d%d%d",&len,&wei,&local);
        for(i=0;i<len;i++)
        for(j=0;j<wei;j++)
        scanf("%d",&s[i][j].p);
        for(i=0;i<len;i++)
        for(j=0;j<wei;j++)
        scanf("%d",&s[i][j].e);
        for(i=0;i<len;i++)
        sort(s[i],s[i]+wei,cmp);
        for(j=0;j<wei;j++)
        dp[0][j]=s[0][j].e+abs(s[0][j].p-local);
        for(i=1;i<len;i++)
        {
            top=1;
            tail=0;
            memset(Q,0,sizeof(Q));
            for(k=j=0;j<wei;j++)
            {
                dp[i][j]=0xfffffff;
              while(k<wei&&s[i-1][k].p<=s[i][j].p)
            {
              t=cost(i,k,j);
              while(top<=tail&&cost(i,Q[tail],j)>=t)tail--;
              tail++;
              Q[tail]=k;
              k++;
            }
            if(top<=tail)dp[i][j]=cost(i,Q[top],j)+s[i][j].e;
            }
            top=1;
            tail=0;
            memset(Q,0,sizeof(Q));
            for(k=j=wei-1;j>=0;j--)
            {
              while(k>=0&&s[i-1][k].p>s[i][j].p)
            {
              t=cost(i,k,j);
              while(top<=tail&&cost(i,Q[tail],j)>=t)tail--;
              tail++;
              Q[tail]=k;
              k--;
            }
            if(top<=tail&&(dp[i][j]>cost(i,Q[top],j)+s[i][j].e))dp[i][j]=cost(i,Q[top],j)+s[i][j].e;
            }
         }
       int mi=0xfffffff;
       for(i=0;i<wei;i++)
       mi=min(mi,dp[len-1][i]);
       cout<<mi<<endl;
    }
    return 0;
}
