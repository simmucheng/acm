#include<stdio.h>
int main()
{
    double s[14],a=0,b,c=0,s;
    int i;
    for(i=5;i>=1;i--)
        scanf("%lf",&s[i]);
    for(i=5;i>=1;i--)
        a=a+s[i]*s[i];
        c=c+s[i];
        b=c/5;
        s=(a-5*b*b)/4;
        printf("%lf %lf %lf",a,b,s);
    return 0;
}
