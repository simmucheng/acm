#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int extendgcd(__int64 aa,__int64 bb,__int64 &xx,__int64 &yy)
{
    if(bb==0)
    {
        xx=1;
        yy=0;
        return aa;
    }
    __int64 nn=extendgcd(bb,aa%bb,xx,yy);
    __int64 temp=xx;
    xx=yy;
    yy=temp-(aa/bb)*yy;
    return nn;
}
int main()
{
    __int64 x,y,m,n,l;
    __int64 i,j;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&l)!=EOF)
    {
        __int64 a,b,c,xx,yy;
        c=x-y;
        a=l;
        b=n-m;
        __int64 uu=extendgcd(a,b,xx,yy);
        if(((c%uu)+uu)%uu!=0)printf("Impossible\n");
        else
        {
           __int64 kk=yy*(c/uu);
           __int64 ee=(a>0?a:-a);
           if(kk<0)
           {
               kk+=(-kk/ee+1)*ee;
           }
           cout<<kk%((a/uu>0)?(a/uu):(-a/uu))<<endl;
        }
    }
    return 0;
}
