#include<stdio.h>
int main()
{
    int a,b,m,n,i,j,s[40];
    s[0]=1;
    s[1]=2;
        for(i=2;i<40;i++)
        s[i]=s[i-1]+s[i-2];
     scanf("%d",&n);
     while(n--)
     {
         scanf("%d",&m);
         printf("%d\n",s[m-2]);
     }
     return 0;
}
