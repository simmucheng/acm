#include<stdio.h>
int main()
{
     long n,i,j,a;
     while(scanf("%ld",&n)==1)
     {
         if(n==0)break;
         j=0;
     for(i=0;i<n;i++)
     {
         scanf("%ld",&a);
         j=j^a;
     }
     printf("%ld\n",j);}
     return 0;
}
