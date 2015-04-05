#include<stdio.h>
int main()
{
    int i,j,k,t,a,z,x,y;
    long m;
    while(scanf("%d",&z)==1)
    {
        m=0;
        a=z/3;
        for(i=0;i<=a;i++)
            m=m+((z-i*3)/2+1);
        printf("%ld\n",m);
    }
    return 0;
}
