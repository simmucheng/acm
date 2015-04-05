#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 5e9
using namespace std;
int sum[1200];
int s[1200][1200];
int mark[1200];
int nu[1200];
void maketree(int nn,int mm)
{
    int step=0;
    int num=0;
    sum[1]=0;
    int get=1;
    while(get>0)
    {
        get=-1;
        int ma=N;
        for(int ii=1;ii<=nn;ii++)
        {
            if(ma>sum[ii]&&!mark[ii])
            {
                get=ii;
                ma=sum[ii];
            }
        }
        nu[step]=ma;
        step++;
        mark[get]=1;
        for(int ii=1;ii<=nn;ii++)
        {
            if(s[get][ii]<sum[ii]&&!mark[ii])
            sum[ii]=s[get][ii];
        }
    }
    return ;
}
void init(int mm)
{
    for(int ii=1;ii<=mm;ii++)
    {
        mark[ii]=0;
        sum[ii]=N;
    }
    for(int ii=1;ii<=mm;ii++)
    {
        for(int jj=1;jj<=mm;jj++)
        s[ii][jj]=N;
    }
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n),m||n)
    {
        init(m);
        for(i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            s[a][b]=c;
            s[b][a]=c;
        }
       maketree(m,n);
       sort(nu,nu+m+1);
       int yy=nu[(m-1)/2+1];
       printf("%d\n",yy);
    }
    return 0;
}
