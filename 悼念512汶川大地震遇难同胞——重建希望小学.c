#include<stdio.h>
int main()
{
    __int64 s[35];
    int i,j,m,n;
    s[1]=1;
    s[2]=3;
    scanf("%d",&m);
    while(m--)
       {
           scanf("%d",&n);
           for(i=3;i<=n;i++)
           s[i]=s[i-1]+2*s[i-2];
           printf("%I64d\n",s[n]);
       }
       return 0;
}
