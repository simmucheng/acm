#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
double s[10][10];
double d[20][10][10][10][10];
double get(int x1,int y1,int x2,int y2);
double dfs(int step,int x1,int y1,int x2,int y2)
{
    if(step==0)
    {
        return get(x1,y1,x2,y2);
    }
    double mi=0xfffffff;
    for(int ii=x1;ii<=x2;ii++)
    {
        mi=min(d[step-1][ii][y1][x2][y2]+get(x1,y1,ii-1,y2),mi);
        mi=min(d[step-1][x1][y1][ii][y2]+get(ii+1,y1,x2,y2),mi);
    }
    for(int ii=y1;ii<=y2;ii++)
    {
        mi=min(d[step-1][x1][ii][x2][y2]+get(x1,y1,x2,ii-1),mi);
        mi=min(d[step-1][x1][y1][x2][ii]+get(x1,ii+1,x2,y2),mi);
    }
    return mi;
}
double get(int x1,int y1,int x2,int y2)
{
    double sum=0;
    sum=s[x2][y2]-s[x2][y1-1]-s[x1-1][y2]+s[x1-1][y1-1];
    return sum*sum;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                {
                    scanf("%lf",&s[i][j]);
                    s[i][j]+=s[i][j-1]+s[i-1][j]-s[i-1][j-1];
                }
        for(int kk=0;kk<n;kk++)
          for(int xx1=1;xx1<=8;xx1++)
              for(int yy1=1;yy1<=8;yy1++)
                  for(int xx2=xx1;xx2<=8;xx2++)
                      for(int yy2=yy1;yy2<=8;yy2++)
                          d[kk][xx1][yy1][xx2][yy2]=dfs(kk,xx1,yy1,xx2,yy2);
        double ee=d[n-1][1][1][8][8]/(n*1.0)-(s[8][8]*s[8][8]*1.0/(n*n*1.0));
        printf("%.3f\n",sqrt(ee));
    }
    return 0;
}
