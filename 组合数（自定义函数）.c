#include<stdio.h>
long long f(int z)
{
    int i;
    long long k=1;
    for(i=1;i<=z;i++)
    {
        k*=i;
    }
    return k;
}
int main ()
{
    int n,m;
    scanf("%d%d",&m,&n);
    //printf("%lld %lld\n",f(m),f(n));
    printf("%lld",f(m)/(f(m-n)*f(n)));
    return 0;
}
