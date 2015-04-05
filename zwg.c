#include <stdio.h>
#include <math.h>
int main()
{
    float n=100000.0,y,s=0.0;
    int i;
    for(i=1;i<=100000;i++)
        s=s+1/(n+i);
    printf("%f\n",s);
    printf("绝对误差为：%.15f\n",log(2.0)-s);
    printf("相对误差为：%.15f\n",(log(2.0)-s)/s);
    return 0;
}
