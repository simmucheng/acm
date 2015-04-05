#include<stdio.h>
int main ()
{
    int m,n,k,i;
    for(i=100;i<=999;i++)
    {
        m=i/100;
        n=i%100/10;
        k=i%10;
        //printf("%d %d %d %d\n",m,n,k,i);
        if(i==m*m*m+n*n*n+k*k*k)printf("%d\n",i);
    }
    return 0;
}
