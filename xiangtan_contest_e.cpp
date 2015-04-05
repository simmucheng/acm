#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define eps 1e-8
double xx,yy;
void getpoint(double aa1,double bb1,double cc1,double aa2,double bb2,double cc2)
{
    yy=(aa2*cc1-aa1*cc2)/(aa2*bb1-aa1*bb2);
    if(yy<0)yy-=eps;
    else yy+=eps;
    xx=(bb2*cc1-bb1*cc2)/(aa1*bb2-aa2*bb1);
    if(xx<0)xx-=eps;
    else xx+=eps;
    return ;
}
int gcd(int aa,int bb);
int dir(double x1,double y1,double x2,double y2)
{
    return gcd((int)(fabs(x2-x1)+eps),(int)(fabs(y2-y1)+eps));
}
int gcd(int aa,int bb)
{
    while(bb)
    {
        __int64 tt=bb;
        bb=aa%bb;
        aa=tt;
    }
    return aa;
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        __int64  sum=0;
        double a1,a2,a3,b1,b2,b3,c1,c2,c3;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&a1,&b1,&c1,&a2,&b2,&c2,&a3,&b3,&c3);
        getpoint(a1,b1,c1,a2,b2,c2);
        double xx1=xx;
        double yy1=yy;
       // cout<<xx<<' '<<yy<<endl;
        getpoint(a1,b1,c1,a3,b3,c3);
        double xx2=xx;
        double yy2=yy;
        //cout<<xx<<' '<<yy<<endl;
        getpoint(a2,b2,c2,a3,b3,c3);
        double xx3=xx;
        double yy3=yy;
       // cout<<xx<<' '<<yy<<endl;
        sum=dir(xx1,yy1,xx2,yy2)+dir(xx1,yy1,xx3,yy3)+dir(xx2,yy2,xx3,yy3);
        printf("%I64d\n",sum);
    }
    return 0;
}
