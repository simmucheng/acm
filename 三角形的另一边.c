#include<stdio.h>
#include<math.h>
int main ()
{
    double a,b,c,d;
    scanf("%lf %lf %lf",&b,&c,&d);
    d=d/180*3.1415926;
    a=sqrt(b*b+c*c-2*b*c*cos(d));
    printf("%g",a);
    return 0;
}
