#include<stdio.h>
#include<math.h>
int main()
{
    double x1,x2,x3,y1,y2,y3,m,a,b,c,s ;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        x1=x1*1.0;
        x2=x2*1.0;
        x3=x3*1.0;
        y1=y1*1.0;
        y2=y2*1.0;
        y3=y3*1.0;
a=((y1-y2)*(x2-x3)-(y2-y3)*(x1-x2))/( (x1*x1-x2*x2)*(x2-x3)-(x1-x2)*(x2*x2-x3*x3));
s=(-a*(x3-x2)*(x3-x2)*(x3-x2))/6;
     printf("%.2f\n",s);
    }
    return 0;
}
