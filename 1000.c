#include<stdio.h>
int main()
{
   char a,h,s[100],b[100];
   int i,j,n,m;
   a=getchar();
    m=0;
   while(a!='A'){
   a=a-1;
   m++;
   for(n=1;n<m;n++)
            {
                printf(" ");
            }
   for(i=0;i<a-63;i++){

   s[i]='A'+i;
   printf("%c",s[i]);
   }
   for(j=0;j<a-64;j++){
   b[j]=a-j;
   printf("%c",b[j]);
   }
   putchar('\n');
   }
   return 0;
}
