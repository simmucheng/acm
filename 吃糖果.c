#include<stdio.h>
int main()
{
    long a,b,m,n,i,j,d,e;
    long long c;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
    {
        c=0;
        e=0;
        a=0;
        scanf("%ld",&m);
        for(j=1;j<=m;j++)
           {
               scanf("%ld",&d);
                 c=c+d;
                if(d>e)e=d;
           }
           if(e>c-e+1)printf("No\n");
           else printf("Yes\n");
     }
     return 0;
}
