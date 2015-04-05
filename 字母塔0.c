#include<stdio.h>
int main()
{
   char a,s[100],b[100],c[100];
   int i,j,n;
   a=getchar();
   b=a;
   while(a!='A'){
   a=a-1;


   for(i=0;i<a-65;i++){
   s[i]='A'+i;
   printf("%c",s[i]);
   }
   for(j=1;j<a-64;j++){
   b[j]=a-j;
   printf("%c",b[j]);
   }
   putchar('\n');
   printf("%d",n);
   }
   return 0;
}
