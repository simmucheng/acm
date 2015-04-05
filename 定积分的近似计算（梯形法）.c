#include<stdio.h>
#include<math.h>
int main()
{
     int i;
    double a=0.0;
    for(i=0;i<=9;i++)
       {
           a=a+1/(1.05+i*0.1);
       }
       printf("精确计算: %.9f\n",log(2.0));
       printf("近似计算: %.9f\n",a*0.1);
       printf("误差估计: %.9f",log(2.0)-a*0.1);
       return 0;
}
