#include<stdio.h>
int main()
{
    double s[14],a[14],b[14],c[14];
    int i;
    for(i=12;i>=3;i--)
        scanf("%lf",&s[i]);
    for(i=12;i>=3;i--)
    {
        a[i]=s[i]*s[i];
        if(i>=8){
            b[i]=a[i]-s[i-5]*s[i-5];
            c[i]=b[i]*1000/(20*589.3);
            }
        else {b[i]=0;c[i]=0;}
    printf("%lf %lf %lf\n",a[i],b[i],c[i]);
    }
    return 0;
}
