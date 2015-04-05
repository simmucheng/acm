#include<stdio.h>
int main ()
{
double a,c=0.0;
int i;
for(i=1;i<=12;i++){
scanf("%lf",&a);
c=c+a;
}
printf("$%.2f\n",c/12);
return 0;
}
