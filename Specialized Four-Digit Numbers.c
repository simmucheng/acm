#include<stdio.h>
int main()
{
    int a,b,c,d,n,i,m,x,y;
    for(i=2992;i<10000;i++)
    {

            b=i/1000+i%1000/100+i%100/10+i%10;
            c=i/(12*12*12)+i%(12*12*12)/(12*12)+i%(12*12)/12+i%12;
            d=i/(16*16*16)+i%(16*16*16)/(16*16)+i%(16*16)/16+i%16;
            if(b==c&&b==d)printf("%d\n",i);
    }
    return 0;
}
