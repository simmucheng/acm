#include<stdio.h>
int main()
{
    int a,b,c,n,m,i,j;
    double x;
    while(scanf("%d",&n)==1)
    {
        if(n==0)break;
        a=0;
        b=0;
        c=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&x);
            if(x>0.0)a++;
            else if(x<0)c++;
            else b++;
        }
        printf("%d %d %d\n",c,b,a);
    }
    return 0;
}
