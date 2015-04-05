#include<stdio.h>
int main()
{
    __int64 s[23];
    int i,j,m,n,a,b;
    scanf("%d",&n);
    s[1]=3;
    while(n--)
    {
        scanf("%d",&m);
        for(i=2;i<=m;i++)
        s[i]=s[i-1]*2+2*i-3;
        printf("%I64d\n",s[m]);
    }
    return 0;
}
