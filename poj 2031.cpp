#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define INF 0xfffffff
using namespace std;
struct node
{
  double x;
  double y;
  double z;
  double r;
}s[110];
int mark[110],n;
double w[110];
double len[110][110];
double distence(node a,node b)
{
    double t=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
    if(t<a.r+b.r)return 0;
    return t-a.r-b.r;
}
double prim(node e,int u)
{
    double num=0;
    int ii,jj;
    int mi=0;
    double tt=0;
    w[0]=0;
    while(mi>-1)
    {
        mi=-1;
        num+=tt;
        tt=0xfffffff;
        for(ii=0;ii<u;ii++)
        {
            if(!mark[ii]&&w[ii]<tt)
            {
                mi=ii;
                tt=w[ii];
            }
        }
        //cout<<mi<<endl;
        mark[mi]=1;
        //cout<<tt<<endl;
        for(ii=0;ii<u;ii++)
        {
            if(!mark[ii]&&len[mi][ii]<w[ii])
            w[ii]=len[mi][ii];
        }
    }
    return num;
}
void init()
{
    for(int l=0;l<n;l++)
    w[l]=INF;
}
int main()
{
    int i,j,m;
    while(scanf("%d",&n),n)
    {
        memset(mark,0,sizeof(mark));
        init();
        for(i=0;i<n;i++)
            scanf("%lf%lf%lf%lf",&s[i].x,&s[i].y,&s[i].z,&s[i].r);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                len[i][j]=distence(s[i],s[j]);
                //cout<<len[i][j]<<' '<<i<<' '<<j<<endl;
            }
        double rr=prim(s[0],n);
        printf("%.3f\n",rr);
    }
    return 0;
}
