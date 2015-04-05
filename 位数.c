#include<stdio.h>
int main ()
{
    /*freopen("位数.in","r",stdin);
    freopen("位数.out","w",stdout);
    int a,b;
   scanf("%d%d",&a,&b);
   printf("%d\n",a+b);
    return 0;
}
*/


     int a,i=1;
     scanf("%d",&a);
     while(1)
     {
         if(a/10!=0)
         {
             a/=10;
             i++;
         }
         else break;
         //printf("%d\n",a);
     }
     printf("%d",i);
}
