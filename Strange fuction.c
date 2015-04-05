#include<stdio.h>
#include<math.h>
int main()
{
    double ap(double a);
    double m,a,b,c,x,e;
    int Y,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&Y);
    a=0.0;
    b=100.0;
     while(fabs(ap(c)-Y)>0.00001)
       {
             c=(a+b)/2.0;
             if((ap(c)-Y)>0) b=c;
             else a=c;
             if((ap(c)-Y)==0){x=c;break;}
       }
       if((ap(c)-Y)!=0)x=(a+b)/2;
       e=6*x*x*x*x*x*x*x+8*x*x*x*x*x*x+7*x*x*x+5*x*x-Y*x;
       printf("%.4lf\n",e);
    }
    return 0;
}
double ap(double a)
{
    double b;
    b=42.0*a*a*a*a*a*a+48*a*a*a*a*a+21*a*a+10*a;
    return (b);
}

