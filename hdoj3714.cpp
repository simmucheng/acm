#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct zb
{
 int a;
 int b;
 int c;
}s[10010];
double findmax(double x,int n)
{
    double mi=-1*0xfffffff;
    int k;
    double r;
    for(k=0;k<n;k++)
    {
        r=s[k].a*x*x+s[k].b*x+s[k].c;
        mi=max(mi,r);
    }
    return mi;
}
int main()
{
    int i,j,m,n;
    double m1;
    double m2;
    double zmax1,zmax2;
    scanf("%d",&n);
    while(n--)
    {
        int num;
        scanf("%d",&num);
        for(i=0;i<num;i++)
        scanf("%d%d%d",&s[i].a,&s[i].b,&s[i].c);
        double r=0.0;
        double l=1000.0;
        zmax1=10;
        zmax2=1;
        while(abs(zmax1-zmax2)>1e-8){
        m1=(r+l)/2;
        m2=(m1+l)/2;
        zmax1=findmax(m1,num);
        zmax2=findmax(m2,num);
        if(zmax1>zmax2)r=m1;
        else l=m2;
        }
        printf("%.4lf\n",(zmax1+zmax2)/2);
    }
    return 0;
}
