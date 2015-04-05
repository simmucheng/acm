#include<stdio.h>
int main()
{
   int a,b,m,n,i,j,s[55];
   s[0]=0;
   s[1]=1;
   s[2]=2;
   s[3]=3;
   s[4]=4;
   for(i=5;i<=55;i++)
   {
       s[i]=s[i-1]+s[i-3];
   }
    while(scanf("%d",&a)==1)
    {
    if(a==0)break;
    printf("%d\n",s[a]);
    }
    return 0;
}

