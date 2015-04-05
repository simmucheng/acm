#include<stdio.h>
#include<math.h>
double y(int x0,int y0,double x1,double y1,double x2,double y2)
{
    return x0*y1+x2*y0+x1*y2-x2*y1-x0*y2-x1*y0;
}
int main ()
{
    int i,j,k=0;
    double x0,x1,x2,y0,y1,y2,m1,m2,m3;
    scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2);
    for(i=1;i<100;i++)
    {
        for(j=1;j<100;j++)
        {
            m1=y(i,j,x0,y0,x1,y1);
            m2=y(i,j,x1,y1,x2,y2);
            m3=y(i,j,x2,y2,x0,y0);
            if(m1>0&&m2>0&&m3>0)k++;
            else if(m1<0&&m2<0&&m3<0)k++;
        }
    }
    printf("%d",k);
    return 0;
}
