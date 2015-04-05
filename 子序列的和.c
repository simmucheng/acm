#include<stdio.h>
int main()
{
    int i,j;
    long m,n;
    long double c=0.0;
    scanf("%ld%ld",&n,&m);
    //printf("%ld %ld\n",n,m);
    for(i=n;i<=m;i++)
    {
        c=c+1.0/(i*i);
        printf("%.5lf\n",c);
    }
    printf("%.5lf\n",c);
    return 0;

}
