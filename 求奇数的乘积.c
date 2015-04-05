#include<stdio.h>
int main()
{
    int a,b,m,n,i,j,x,y;
    while(scanf("%d",&a)==1)
    {
        x=1;
        for(i=0;i<a;i++)
        {
            scanf("%d",&b);
            if(b%2==1)x=x*b;
        }
        printf("%d\n",x);
    }
    return 0;
}
