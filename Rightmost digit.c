#include<stdio.h>
int main ()
{
    unsigned long a,i,c,j,b,m;
     int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lu",&a);
        if(a==0){printf("1\n");continue;}
        b=a%10;
        c=a%4;
        m=1;
        for(j=1;j<=c;j++)
            m=b*m;
            if(c==0)m=b*b*b*b;
    printf("%lu\n",m%10);}
    return 0;
}
