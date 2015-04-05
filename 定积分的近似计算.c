#include<stdio.h>
#include<math.h>
int main ()
{
    int i;
    double a=0.0;
    double s[11]={1.04,1.16,1.25,1.36,1.44,1.56,1.63,1.75,1.87,1.96,0.0};
    for(i=0;i<=9;i++)
      {
          a=a+1/s[i];
      }
      printf("精确计算: %.9f\n",log(2.0));
      printf("近似计算: %.9f\n",a*0.1);
      printf("误差估计: %.9lf",log(2.0)-a*0.1);
      return 0;
}
