#include<stdio.h>
int main()
{
    double a,b;
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        a=1.0;
        for(i=1;i<m;i++)
            a=a*(m-1)/m;
        printf("%.2lf%%\n",a*100);
    }
    return 0;
}
