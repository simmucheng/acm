#include<stdio.h>
int main()
{
    double a,c,s,p;
    int b;
    int i=0,j,n,m;
    while(scanf("%lf%d%lf",&a,&b,&c)==3)
    {
        i++;
        if(b==0)break;
        s=3.1415927*a*b/12/5280;
        p=s/(c/3600);
        printf("Trip #%d: %.2lf %.2lf\n",i,s,p);
    }
    return 0;
}
