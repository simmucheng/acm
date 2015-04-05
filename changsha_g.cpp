#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<fstream>
#include<algorithm>

#define MAX(a,b)((a)>(b)?(a):(b))
using namespace std;

//ofstream oo("1.txt");
const int MAXN=1e8;
int pp[110][110];
int next[110][110];
int dp[110][310];
int vp[110];
int cp[110];
int markmin[110][310];
struct node
{
    int x,y;
    int ti;
    int va;
};
struct cmp
{
    bool operator()(node a,node b)
    {
        return a.va<b.va;
    }
};
void floyd(int nn)
{
    for(int ii=0;ii<nn;ii++)
    {
        for(int jj=0;jj<nn;jj++)
        {
            for(int kk=0;kk<nn;kk++)
                pp[ii][jj]=min(pp[ii][kk]+pp[kk][jj],pp[ii][jj]);
        }
    }
    return ;
}
void init(int nn,int tt)
{
    for(int ii=0;ii<nn;ii++)
    {
        pp[ii][ii]=0;
        for(int jj=0;jj<nn;jj++)
        {
            if(ii==jj)continue;
            pp[ii][jj]=MAXN;
        }
    }
   // memset(next,0,sizeof(next));
    for(int ii=0;ii<nn;ii++)
    {
        for(int jj=0;jj<=tt;jj++)
        {
            dp[ii][jj]=-MAXN;
        }
    }
    return ;
}
void dij(int sta,int nn,int tt)
{
   priority_queue<node,vector<node>,cmp> q;
   dp[sta][0]=0;
   dp[sta][cp[sta]]=vp[sta];
   node aa,bb;
   aa.x=sta;
   aa.y=0;
   aa.va=0;
   bb.x=sta;
   bb.y=cp[sta];
   bb.va=vp[sta];
   q.push(aa);
   q.push(bb);
   while(!q.empty())
   {
       node ee=q.top();
       q.pop();
       int xx1=ee.x;
       int yy1=ee.y;
       int vv1=ee.va;
       //oo<<"xx1 = "<<xx1<<endl;
       if(vv1<dp[xx1][yy1])continue;
       for(int ii=0;ii<nn;ii++)
       {
           if(ii==xx1||pp[xx1][ii]==MAXN)continue;
              int jj=pp[ii][xx1];
              if(jj+yy1<=tt)
              if(dp[ii][jj+yy1]<dp[xx1][yy1])
                {
                    dp[ii][jj+yy1]=dp[xx1][yy1];
                    node rr;
                    rr.x=ii;
                    rr.x=ii;
                    rr.y=jj+yy1;
                    rr.va=dp[xx1][yy1];
                    q.push(rr);
                    //cout<<rr.x<<' '<<rr.y<<' '<<rr.va<<endl;
                }
               if(jj+yy1+cp[ii]<=tt)
               if(dp[ii][jj+yy1+cp[ii]]<dp[xx1][yy1]+pp[xx1][yy1]+vp[ii])
                {
                    dp[ii][jj+yy1+cp[ii]]=dp[xx1][yy1]+vp[ii];
                    node rr;
                    rr.x=ii;
                    rr.y=jj+yy1+cp[ii];
                    rr.va=dp[xx1][yy1]+vp[ii];
                    q.push(rr);
                   // oo<<"xx = "<<rr.x<<' '<<"yy = "<<rr.y<<' '<<"va = "<<rr.va<<endl;
                }
       }
   }
   return ;
}
int main()
{
    int i,j,m,n,s,t,e,w;
    scanf("%d",&w);
    for(int kk=1;kk<=w;kk++)
    {
        scanf("%d%d%d%d%d",&n,&m,&t,&s,&e);
        init(n,t);
        for(i=0;i<n;i++)
            scanf("%d",&cp[i]);
        for(i=0;i<n;i++)
            scanf("%d",&vp[i]);
        for(i=1;i<=m;i++)
        {
            int a,c,b;
            scanf("%d%d%d",&a,&b,&c);
            pp[a][b]=c;
            pp[b][a]=c;
           // next[a][++next[a][0]]=b;
           // next[b][++next[b][0]]=a;
        }
        floyd(n);
        printf("Case #%d:\n",kk);
        if(pp[s][e]==MAXN)
        {
            printf("0\n");
            continue;
        }
        dij(s,n,t);
        int getmax=-1;
        for(i=t;i>=0;i--)
            getmax=MAX(getmax,dp[e][t]);
        printf("%d\n",getmax);
    }
    return 0;
}
