#include<stdio.h>
#include<stdlib.h>
int cmp(const void *x,const void *y)
{
    return(*(int *)x-*(int *)y);
}
long s[10000009];
int main()
{
   long a,b,m,n,i,j,k,c;
   while(scanf("%ld%ld",&a,&b)==2)
   {
    for(i=0;i<a;i++)
        scanf("%ld",&s[i]);
        qsort(s,a,sizeof(s[0]),cmp);
       for(j=a-1;j>a-b-1;j--)
       printf("%ld ",s[j]);
       putchar('\n');
   }
    return 0;
}

