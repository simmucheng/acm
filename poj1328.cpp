#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
double d;
struct node
{
    double x;
    double y;
}s[1012];
int cmp(node x1,node x2)
{
    if(x1.x!=x2.x)
    return x1.x<x2.x;
}
double su(double c)
{
    double er;
    er=pow(d,2.0)-pow(c,2.0);
    return sqrt(er);
}
int main()
{
    int a,b,i,j;
    int m,n;
    int ca=0;
    while(cin>>n>>d,n||d)
    {
        int mark=0;
        int nu=0;
        int ax,ay;
        for(i=0;i<n;i++)
        {
            cin>>ax>>ay;
            if(ay>d)mark=1;
            s[i].x=ax-su(ay);
            s[i].y=ax+su(ay);
        }
        if(mark==1)nu=-1;
        else
        {
        sort(s,s+n,cmp);
          for(i=0;i<n;i++)
          {
              int e=0;
              double en=s[i].y;
           for(j=i+1;j<n;j++)
           {
               if(en>=s[j].x)e++;
               else break;
               if(en>s[j].y)en=s[j].y;
           }
           i+=e;
           nu++;
          }
        }
        printf("Case %d: %d\n",++ca,nu);
    }
    return 0;
}
