#include<stdio.h>
#include<math.h>
int main()
{
    double a;
    a=-3.0*(2.0*2*2*2-1*1*1*1)/80.0+41.0*(2.0*2*2-1*1*1)/120.0-101.0*(2.0*2-1*1)/80.0+53.0*(2.0-1)/20.0;
    printf("��ȷ����: %.9f\n",log(2.0));
    printf("���Ƽ���: %.9f\n",a);
    printf("������: %.9f\n",log(2.0)-a);
    return 0;
}
