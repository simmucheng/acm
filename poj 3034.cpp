#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
#include<cmath>
#include<algorithm>
#include<fstream>
#define N -10000
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)
using namespace std;
ofstream pp("1.txt");
int dp[12][22][22];
int ss[12][22][22];
int get(int aa,int bb)
{
    return aa*aa+bb*bb;
}
int value(int i1,int j1,int k1,int jj1,int kk1)
{
    int ret=0;
    if(j1==jj1&&k1==kk1)return ss[i1][j1][k1];
    int mm1=MIN(j1,jj1);
    int mm2=MAX(j1,jj1);
    if(jj1-j1==0)
    {
        for(int ii=mm1;ii<=mm2;ii++)
        ret+=ss[i1][ii][j1];
        return ret;
    }
    double kk=(kk1-k1)/(jj1-j1);
    for(int ii=mm1;ii<=mm2;ii++)
    {
        double y3=kk*(ii-j1)+k1;
        if((y3-k1)*(jj1-j1)!=(ii-j1)*(kk1-k1))continue;
        if(ss[i1][ii][(int)y3])ret+=1;
    }
    return ret;
}
void init(int nn)
{
    for(int kk=0;kk<=10;kk++)
    for(int ii=0;ii<=nn;ii++)
    for(int jj=0;jj<nn;jj++)
    dp[kk][ii][jj]=0;
    return ;
}
int main()
{
    int i,j,m,n,b,k;
    while(scanf("%d%d%d",&n,&b,&m,n||b||m))
    {
     int gettt=N;
     int mm=N;
     init(n);
     for(i=0;i<m;i++)
     {
        int  xx,yy,tt;
        scanf("%d%d%d",&xx,&yy,&tt);
        ss[tt][xx][yy]=1;
        if(tt==1)
        gettt=MAX(tt,gettt);
     }
     cout<<dp[1][1][2]<<endl;
     for(i=1;i<=gettt;i++)
     {
         for(j=0;j<n;j++)
         {
             for(k=0;k<n;k++)
             {
                 for(int jj=(j-b>0?j-b:0);jj<=j+b;jj++)
                 {
                     for(int kk=(k-b>0?k-b:0);kk<=k+b;kk++)
                     {
                         //cout<<"tttt"<<' '<<jj<<' '<<kk<<endl;
                         if(get(jj-j,kk-k)>b*b)continue;
                         int tt=value(i,j,k,jj,kk);
                         dp[i][j][k]=MAX(dp[i-1][jj][kk]+tt,dp[i][j][k]);
                         pp<<i<<' '<<j<<' '<<k<<' '<<' '<<dp[i][j][k]<<' '<<tt<<"----"<<jj<<' '<<kk<<' '<<dp[i-1][jj][kk]<<endl;
                     }
                 }
                 mm=MAX(mm,dp[i][j][k]);
             }
         }
     }
     printf("%d\n",mm);
     }
    return 0;
}
