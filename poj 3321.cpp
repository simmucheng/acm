#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct node1
{
    int ver;
    int next;
}w[100100];
int head[100100];
struct node
{
    int l;
    int r;
    int nu;
}r[100100];
int mark[100100];
int n;
int edgenum;
int relate(int aa,int bb)
{
    w[edgenum].ver=bb;
    w[edgenum].next=head[aa];
    head[aa]=edgenum;
    edgenum++;
}
int lowbit(int nn)
{
    return nn&(-nn);
}
int get_sum(int nn)
{
    int sum=0;
    while(nn>0)
    {
        sum+=mark[nn];
        nn-=lowbit(nn);
    }
    return sum;
}
void add(int nn,int worth)
{
    while(nn<=100100)
    {
        mark[nn]+=worth;
        nn+=lowbit(nn);
    }
    return ;
}
int time;
void dfs(int nn)
{
       time++;
       r[nn].l=time;
       for(int ii=head[nn];ii!=-1;ii=w[ii].next)
       {
           dfs(w[ii].ver);
       }
       r[nn].r=time;
       return ;
}
void init(int nn)
{
    edgenum=0;
    for(int ii=1;ii<=nn;ii++)
    {
        r[ii].nu=1;
        head[ii]=-1;
        mark[ii]=0;
    }
    return ;
}
int main()
{
    int i,j,m,a,b;
    while(scanf("%d",&n)!=EOF)
    {
        int len=n;
        init(len);
        time=0;
        n--;
        while(n--)
        {
            scanf("%d%d",&a,&b);
            relate(a,b);
        }
        dfs(1);
        for(i=1;i<=len;i++)
        add(i,1);
        scanf("%d",&m);
        while(m--)
        {
          char s[2];
          int e;
          scanf("%s",s);
          if(s[0]=='C')
          {
              scanf("%d",&e);
              if(r[e].nu==1){add(r[e].l,-1);r[e].nu=0;}
              else {add(r[e].l,1);r[e].nu=1;}
          }
          else
          {
              scanf("%d",&e);
              int tt=get_sum(r[e].r)-get_sum(r[e].l-1);
              printf("%d\n",tt);
          }
        }
    }
	return 0;
}
