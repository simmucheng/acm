#include<stdio.h>
double f[10001];
double min(double c1,double c2)
{
  if(c1<c2)
  return c1;
  else
  return c2;
}
int main()
{
    int n,m,i,j,sp,s[1001],x,y;
    double a,b,w[1001];
    double min(double c1,double c2);
    while(scanf("%d%d",&sp,&n),sp||n)
    {
        for(i=0;i<=sp;i++)
        f[i]=1.0;
        a=1.0;
        for(i=0;i<n;i++)
        {
        scanf("%d%lf",&s[i],&w[i]);
        w[i]=1.0-w[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=sp;j>=s[i];j--)
                f[j]=min((f[j-s[i]]*w[i]),f[j]);
        }
        printf("%.1lf%%\n",(1-f[sp])*100);
    }
    return 0;
}
