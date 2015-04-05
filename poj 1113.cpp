#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int x;
    int y;
}w[1100],s[1100];
int cmp(node a,node b)
{
    if((a.y-s[0].y)*(b.x-s[0].x)!=(a.x-s[0].x)*(b.y-s[0].y))
    return (s[0].y-b.y)*(s[0].x-a.x)>(s[0].x-b.x)*(s[0].y-a.y);
    else
    return a.x<b.x;
}
double distence(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0);
}
int judge(node a,node b,node c)
{
    return (b.x-a.x)*(c.y-b.y)-(b.y-a.y)*(c.x-b.x);
}
int main()
{
    int i,j,m,n;
    scanf("%d%d",&n,&m);
    int x1=0xfffffff;
    int y1=0xfffffff;
    int mark;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&s[i].x,&s[i].y);
        if((y1>s[i].y)||(y1==s[i].y&&x1>s[i].x))
        {
            x1=s[i].x;
            y1=s[i].y;
            mark=i;
        }
    }
    swap(s[mark],s[0]);
    sort(s+1,s+n,cmp);
     int aa=0;
    node mm;
    mm.x=s[1].x-s[0].x;
    mm.y=s[1].y-s[0].y;
    for(i=2;i<n;i++)
    {
        node nn;
        nn.x=s[i].x-s[0].x;
        nn.y=s[i].y-s[0].y;
        if(mm.y*nn.x!=mm.x*nn.y){aa=1;break;}
    }
    double sum=0;
    if(aa==0)sum+=2*distence(s[0],s[n-1]);
    else
    {
      int l=0;
      w[0]=s[0];
      for(i=1;i<n;i++)
      {
        if(l<1)w[++l]=s[i];
        while(l>=1)
        {
            if(judge(w[l-1],w[l],s[i])<0)--l;
            else {w[++l]=s[i];break;}
        }
      }
      for(i=0;i<l;i++)sum+=distence(w[i],w[i+1]);
      sum+=distence(w[l],w[0]);
    }
         sum+=2.0*acos(-1)*m;
      printf("%d\n",(int)(sum+0.5));
     return 0;
}
