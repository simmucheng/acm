#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

#define ABS(a)((a)>0?(a):(-a))
using namespace std;

const double MAXN=1e30;
const double eps=1e-8;
struct node1
{
   double cc;
   double disten;
   double bi;
}cost[1200];
int mark[1200];
double ten[1200][1200];
int dd[1200][1200];
double p,q;
struct node
{
    double x;
    double y;
    double cos;
}edge[1200];
double get_distence(node a1,node b1)
{
    return sqrt((a1.x-b1.x)*(a1.x-b1.x)+(a1.y-b1.y)*(a1.y-b1.y));
}
void init(int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        cost[ii].cc=MAXN;
        mark[ii]=0;
    }
    return ;
}
void prim(int nn,double L)
{
    int rr=0;
    p=0;
    q=0;
    cost[1].cc=0;
    while(rr!=-1)
    {
        rr=-1;
        double getmin=MAXN;
        for(int ii=1;ii<=nn;ii++)
        {
            if(cost[ii].cc<getmin&&!mark[ii])
            {
                rr=ii;
                getmin=cost[ii].cc;
            }
        }
        if(rr==-1)break;
        mark[rr]=1;
        q+=cost[rr].disten;
        p+=cost[rr].bi;
        for(int ii=1;ii<=nn;ii++)
        {
            if(!mark[ii]&&(cost[ii].cc>dd[rr][ii]-L*ten[rr][ii]))
               {
                   cost[ii].cc=dd[rr][ii]-L*ten[rr][ii];
                   cost[ii].disten=ten[rr][ii];
                   cost[ii].bi=dd[rr][ii];
               }
        }
    }
    return ;
}
void trans(int nn)
{
    double L=0.0;
    double ans;
    while(1)
    {
        init(nn);
        prim(nn,L);
        ans=p/q;
        //cout<<p<<" "<<q<<endl;
        if(fabs(L-ans)<eps)break;
        L=ans;
    }
    printf("%.3f\n",ans);
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
        {
            double a,b,c;
            scanf("%lf%lf%lf",&a,&b,&c);
            edge[i].cos=c;
            edge[i].x=a;
            edge[i].y=b;
        }
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            ten[i][j]=get_distence(edge[i],edge[j]);
            ten[j][i]=ten[i][j];
            dd[i][j]=abs(edge[i].cos-edge[j].cos);
            dd[j][i]=dd[i][j];
            //cout<<dd[i][j]<<endl;
        }
        trans(n);
    }
    return 0;
}
/*
#define ���÷�
abs���÷�
* /
