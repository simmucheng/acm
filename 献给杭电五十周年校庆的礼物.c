#include<stdio.h>
int main()
{
    __int64 s[1020],x,y;
    int i,j,m,n;
    s[0]=1;
    s[1]=2;
    for(i=2;i<=1019;i++)
        s[i]=s[i-1]+i;
    while(scanf("%d",&n)==1)
     {
         x=s[n-1]*2;
         printf("%d\n",x);
     }
    return 0;
}
