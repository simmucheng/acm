#include<stdio.h>
int main()
{
    __int64 s[60];
    int a,b,m,n,c,i,j;
    s[1]=1;
    s[2]=2;
        for(i=3;i<50;i++)
        s[i]=s[i-1]+s[i-2];
     scanf("%d",&n);
     while(n--)
     {
         scanf("%d%d",&a,&b);
         m=b-a;
         printf("%I64d\n",s[m]);
     }
     return 0;
}
