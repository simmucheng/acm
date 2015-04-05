#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define INF 0.0000001
using namespace std;
struct node
{
    double x;
    double y;
}s[30];
int dblcmp(double d)
{
    if(fabs(d)<INF)return 0;
    return (d>0)?1:-1;
}
double det(double x1,double x2,double y1,double y2)
{
    return x1*y2-x2*y1;
}
double xx(node a,node b,node c)
{
    return  det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
int judge(node a,node b,node c,node d)
{
    if(dblcmp(xx(a,b,c)*xx(a,b,d))<0&&dblcmp(xx(c,d,a)*xx(c,d,b))<0)return 1;
    return 0;
}
double find_x(node a,node b,node c,node d)
{
    double px;
    double s1=fabs(xx(a,b,c));
    double s2=fabs(xx(a,b,d));
    if(s1-s2==0)return -1*0xfffffff;
    px=(c.x*s2-d.x*s1)/(s2-s1);
    return px;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n),n)
    {
        double mx=-1.0*0xfffffff;
        for(i=0;i<n;i++)
        scanf("%lf%lf",&s[i].x,&s[i].y);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
               if(i==j)continue;
               for(int k=0;k<n;k++)
               {
                   node e=s[j];
                   e.y--;
                  if(judge(s[i],e,s[k],s[k+1]))
                  {
                      mx=max(mx,find_x(s[i],e,s[k],s[k+1]));
                      printf("%.3f\n",mx);
                      cout<<i<<' '<<j<<endl;
                      break;
                  }
                  node r1,r2;
                  r1=s[k];r2=s[k+1];
                  r1.y--;
                  r2.y--;
                  //if(judge(s[i],e,r1,r2))mx=max(mx,find_x(s[i],s[j],r1,r2));
                  
               }
            }
        }
        printf("%.3f\n",mx);
    }
    return 0;
}
