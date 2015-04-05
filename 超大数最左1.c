#include<stdio.h>
#include<math.h>
int main()
{
    double m,n;
    int y;
    long a,b;
    while(scanf("%ld",&a)==1)
    {
    m=a*log10(a);
    m=m-floor(m);
    n=pow(10.0,m);
    y=(int)n;
    printf("%d\n",y);
    }
    return 0;

}
