#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double eps=1e-8;
double s[300][300];
double ans[10][300];
int poww(int nn)
{
    int sum=1;
    for(int ii=1;ii<=nn;ii++)
        sum*=2;
    return sum;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        int tt=poww(n);
        for(i=1;i<=tt;i++)
            for(j=1;j<=tt;j++)
            scanf("%lf",&s[i][j]);
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=tt;i++)
            {
                ans[k][i]=ans[k-1][i]*ans[k-1][]*s[][]+
            }
        }
    }
}
