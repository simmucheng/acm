#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAXN 1000
using namespace std;
int num[610],fa[610];
int judge(int nn,char mark)
{
    if(mark=='y')return fa[nn];
    return fa[nn]^1;
}
int main()
{
    int m,n,k;
    while(scanf("%d%d%d",&m,&n,&k)!=EOF)
    {
        int sta_x=1000,sta_y=1001;
        for(int ii=1;ii<=m;ii++)
        {
            int x,y;
            char z[10];
            scanf("%d%d%s",&x,&y,z);
            if(fa[x]==x&&fa[y]==y&&z[0]=='y')
            {
                sta_x+=2;
                fa[x]=sta_x;
                fa[y]=fa[x];
                num[fa[x]-MAXN]+=2;
            }
            else if(fa[x]==x&&fa[y]==y&&z[0]=='n')
            {
                sta_x+=2;
                sta_y+=2;
                fa[x]=sta_x;
                fa[y]=sta_y;
                num[fa[x]-MAXN]++;
                num[fa[y]-MAXN]++;
            }
            else if(fa[x]!=x&&fa[y]==y){fa[y]=judge(x,y,z[0]);num[fa[y]-MAXN]++;}
            else if(fa[x]==x&&fa[y]!=y){fa[x]=judge(y,x,z[0]);num[fa[x]-MAXN]++;}
            else if(fa[x]!=x&&fa[y]!=y)if(fa[y]!=judge(x,z[0])||fa[x]!=judge(y,z[0]))gg=1;
        }
        if(gg==1){printf("-1\n");continue;}
        else
        {
            for(int ii=1;ii<=p1+p2;ii++)
            {
                if(fa[ii]==ii)
                {
                    sta_x+=2;
                    fa[ii]=sta_x;
                    num[fa[ii]-MAXN]++;
                }
            }
            for(int ii=0;ii<=sta_x;ii+=2)
            {
                for(int jj=min(num[ii],num[ii^1]);jj<=p1+p2;jj++)
                {
                    if(jj>=max(num[ii],num[ii^1]))dp[jj]=max(dp[jj-num[ii]]+num[ii],dp[jj-num[ii^1]]+num[ii^1]);
                    else dp[jj]=max(dp[jj-min(num[ii],num[ii^1])]+min(num[ii],num[ii^1]),dp[jj]);
                }
            }
        }
    }
    return 0;
}
