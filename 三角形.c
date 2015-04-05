#include<stdio.h>
int main()
{
    __int64 s[10010];
    int i,j,m,n,a,b;
    s[0]=0;
    s[1]=2;
    s[2]=8;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
     for(i=3;i<=m;i++)
     s[i]=(s[i-1]+s[i-2])*2;
     printf("%I64d\n",s[m]);
    }
    return 0;
}
