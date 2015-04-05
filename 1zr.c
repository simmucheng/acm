#include<stdio.h>
#include<math.h>
int main()
{
   int i,j,m,n;
   int x;
   while(scanf("%d",&x)!=EOF)
   {
       double rr;
       if(x<0||x>30)
       {
           printf("Not define\n");
           continue;
       }
       if(x>=0&&x<10)
       rr=cos(x*1.0+3.0);
       else if(x>=10&&x<20)
       {
           rr=cos(x*1.0+7.5);
           rr*=rr;
       }
       else if(x>=20&&x<30)
       {
           rr=cos(x+4.0);
           rr*=rr;
           rr*=rr;
       }
       printf("%.5f\n",rr);
   }
   return 0;
}
