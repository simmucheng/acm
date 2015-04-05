#include<stdio.h>
int main()
{
    __int64 s[10010];
    int i,j,a,b,m,n;
    scanf("%d",&n);
    s[1]=2;
    while(n--)
    {
        scanf("%d",&m);
        for(i=2;i<=m;i++)
        s[i]=s[i-1]+6*(i-1);

        printf("%I64d\n",s[m]);
    }
    return 0;
}
