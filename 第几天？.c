#include<stdio.h>
int main()
{
   int a,b,c,n,i,j,m,d;
   char x,y;
   while(scanf("%d%c%d%c%d",&a,&x,&b,&y,&c)==5)
   {
       d=0;
       if((a%4==0&&a%100!=0)||a%400==0)
       {
           int s[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
           for(j=0;j<b;j++)d=s[j]+d;
           m=c+d;
       }
       else
       {
            int w[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
            for(j=0;j<b;j++)d=w[j]+d;
            m=c+d;
       }
       printf("%d\n",m);
   }
   return 0;
}
