#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
#include<map>
#include<vector>
#include<functional>
using namespace std;
struct node
{
    int v;
    int w;
}s[1010];
 int ro;
 int m;
int dp[1010][32];
int temp[3200];
int cmp(int x,int y)
{
    if(x!=y)
    return x>y;
}
void init()
{
    for(int k=0;k<320;k++)
    temp[k]=0;
}
void init1()
{
    for(int x=0;x<=ro;x++)
    for(int y=0;y<=320;y++)
    dp[x][y]=0;
}
int main()
{
    int i,j,n,k,l;
    cin>>n;
    while(n--)
    {
        init1();
        scanf("%d%d%d",&m,&ro,&k);
        for(i=0;i<m;i++)
        scanf("%d",&s[i].v);
        for(i=0;i<m;i++)
        scanf("%d",&s[i].w);
        int mi=0;
        for(i=s[0].w;i<=ro;i++)
            dp[i][1]=s[0].v;
        for(i=1;i<m;i++)
        {
            for(j=ro;j>=0;j--)
            {
                int u=0;
                init();
                for(l=1;l<=k;l++)
                {
                    temp[u++]=dp[j][l];
                    int f=dp[j-s[i].w][l]+s[i].v;
                    if(j>=s[i].w)
                    {
                        temp[u++]=f;
                    }
                }
                //cout<<endl;
                sort(temp,temp+u,cmp);
                int x=1;
                for(l=0;l<u;l++)
                {
                    if(temp[l]!=temp[l+1]||(l+1==u-1))
                     dp[j][x++]=temp[l];
                    if(x>k)break;
                }
            }
        }
        cout<<dp[ro][k]<<endl;
    }
    return 0;
}
/*
5
3 2 1
3 2 1
0 1 0
*/
