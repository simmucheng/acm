#include<stdio.h>
#include<math.h>
int main()
{
    double ap(double a);
    double m,a,b,c;
    int Y,n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&Y);
    a=0.0;
    b=100.0;
    if(Y<ap(0)||Y>ap(100)){printf("No solution!\n");continue;}
    else
    {
     while(fabs(ap(c)-Y)>0.00001)
       {
             c=(a+b)/2.0;
             if((ap(c)-Y)>0) b=c;
             else a=c;
             if((ap(c)-Y)==0){printf("%.4lf\n",c);break;}
       }
       if((ap(c)-Y)!=0)printf("%.4lf\n",(a+b)/2);
    }
    }
    return 0;
}
double ap(double a)
{
    double b;
    b=8.0*a*a*a*a+7*a*a*a+2*a*a+3*a+6;
    return (b);
}

