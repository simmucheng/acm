#include<stdio.h>
int main()
{
    __int64 s[60];
    int i,j,m,n,a,b;
    s[1]=1;
    s[2]=2;
    for(i=3;i<55;i++)
    s[i]=s[i-1]+s[i-2];
    while(scanf("%d",&m)==1)
        printf("%I64d\n",s[m]);
    return 0;
}
