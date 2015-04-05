#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int aa,int bb)
{
    while(bb)
    {
        int nn=aa%bb;
        aa=bb;
        bb=nn;
    }
    return aa;
}
void expend(int aa,int bb,int &xx,int &yy)
{
    if(bb==0)
    {
        xx=1;
        yy=0;
        return ;
    }
    expend(bb,aa%bb,xx,yy);
    int nn=xx;
    xx=yy;
    yy=nn-aa/bb*yy;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(gcd(a,b)!=1)
        {
            printf("Not Exist\n");
            continue;
        }
        int x,y;
        expend(a,b,x,y);
        while(x<=0)
            x+=b;
        while(x>0)
            x-=b;
        printf("%d\n",x+b);
    }
}
