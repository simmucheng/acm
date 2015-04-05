#include<stdio.h>
#include<math.h>
int main()
{
    double a;
    a=-3.0*(2.0*2*2*2-1*1*1*1)/80.0+41.0*(2.0*2*2-1*1*1)/120.0-101.0*(2.0*2-1*1)/80.0+53.0*(2.0-1)/20.0;
    printf("精确计算: %.9f\n",log(2.0));
    printf("近似计算: %.9f\n",a);
    printf("误差估计: %.9f\n",log(2.0)-a);
    return 0;
}
