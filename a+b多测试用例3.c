#include<stdio.h>
int main()
{
    int a,b,i;
      i=0;
     while((scanf("%d %d",&a,&b))==2){
     i++;
     printf("Case %d: ",i);
     printf("%d\n",a+b);
     }

}
