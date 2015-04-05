#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define N 1000000
using namespace std;
int next[250][250];
int dp[250][250];
int mark[250];
int b,tt;
//ofstream pp("1.txt");
void DP(int nn)
{
    for(int ii=1;ii<=next[nn][0];ii++)
    DP(next[nn][ii]);
    dp[nn][1]=next[nn][0];
    for(int ii=1;ii<=next[nn][0];ii++)
    {
        for(int jj=b;jj>=1;jj--)
        {
            for(int kk=1;kk<jj;kk++)
            {
                dp[nn][jj]=min(dp[next[nn][ii]][jj-kk]+dp[nn][kk]-1,dp[nn][jj]);

            }
           // pp<<dp[nn][jj]<<' '<<nn<<' '<<jj<<endl;
        }
    }
    return ;
}
int get_ans(int nn)
{
    DP(nn);
    for(int ii=1;ii<=tt;ii++)
    {
        if(ii==nn)continue;
        else dp[ii][b]+=1;
    }
    int getmin=N;
    for(int ii=1;ii<=tt;ii++)
    getmin=min(getmin,dp[ii][b]);
    return getmin;
}
void init(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        mark[ii]=0;
        next[ii][0]=0;
        for(int jj=1;jj<=nn;jj++)
        dp[ii][jj]=N;
    }
    return ;
}
int main()
{
    int k,i,j,m,n;
    int a;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        tt=a;
        init(a);
        for(i=1;i<a;i++)
        {
            int aa,bb;
            scanf("%d%d",&aa,&bb);
            next[aa][++next[aa][0]]=bb;
            mark[bb]=1;
        }
        int rr;
        for(i=1;i<=a;i++)
        {
            if(!mark[i])
            {
                rr=get_ans(i);
                break;
            }
        }
        printf("%d\n",rr);
    }
    return 0;
}
