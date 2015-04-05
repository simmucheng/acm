#include<stdio.h>
int main ()
{
    int a,i,m=-1;
    double count=0.0;
    for(i=1;;i++)
    {
        m=m*(-1);
        count=count+1/(2.0*i-1)*m;
        if((1/(2*i-1.0))<0.000001)//printf("%d\n",i);
        break;
    }
    //printf("%d\n",i);
    printf("¦Ð/4=%f",count);
}
