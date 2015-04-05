#include<stdio.h>
int main()
{
    unsigned int a,b,i,j,k;
    unsigned int m,n;
    while(scanf("%u%u",&a,&b)==2)
    {
        if(a>b){k=a;a=b;b=k;}
        m=0;
        n=0;
        for(i=a;i<=b;i++)
        {
            if(i%2==0)m=m+i*i;
            else n=n+i*i*i;
        }
        printf("%u %u\n",m,n);
    }

}
