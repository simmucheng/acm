#include<stdio.h>
int main()
{
   int price,i,j,m,n,a,b;
   int p[10],num[100];
   scanf("%d",&price);
   scanf("%d",&n);
   for(i=1;i<=n;i++)
       scanf("%d",&p[i]);
   for(i=1;i<=price;i++)
   num[i]=1000;
   num[0]=0;
   for(i=1;i<=n;i++)
   {
       for(j=p[i];j<=price;j++)
       {
           num[j]=(num[j-p[i]]+1)<num[j]?(num[j-p[i]]+1):num[j];
           printf("%d ",num[j]);
       }
       putchar('\n');
   }
   printf("%d\n",num[price]);
   return 0;
}
