#include<stdio.h>
int main()
{
    __int64 s[10010];
    int a,b,i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        s[0]=1;
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            s[i]=s[i-1]+(4*i-3);
        printf("%I64d\n",s[m]);
    }
    return 0;
}
