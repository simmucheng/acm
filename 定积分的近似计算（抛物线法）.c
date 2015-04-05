#include<stdio.h>
#include<math.h>
int main ()
{
    int i,j;
    double a=0.0,n=0.0,m=0.0;
    for(i=0;i<=9;i++)
      {
          m=m+1/(i*0.1+1.05);
      }
    for(j=1;j<=9;j++)
      {
         n=n+1/(i*0.1+1);
      }
      printf("精确计算: %.9f\n",log(2.0));
      printf("近似计算: %.9f\n",((2-1)*(1+2+4*m+2*n)/60));
      printf("误差估计: %.9f",log(2.0)-((2-1)*(1+2+4*m+2*n)/60));
      return 0;
}
