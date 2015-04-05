#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
using namespace std;
double turn(long long x1,long long y1)
{
    if(y1<x1)return 0;
    double dd=1;
    __int64 l;
    for(l=x1+1;l<=y1;l++)
    dd*=l;
    for(l=2;l<=(y1-x1);l++)
    dd/=l;
    return dd;
}
int main()
{
    int i,j,m,n;
    long long  x,y;
    while(scanf("%lld%lld",&x,&y),x||y)
    {
        double sum=0;
        if(x<y)swap(x,y);
        if(x==1&&y==1)printf("2\n");
        else
        {
        sum+=turn(x-2,x+y-2)+2*turn(x-1,x+y-2)+turn(x,x+y-2);
        printf("%.0f\n",sum);
        }
    }
    return 0;
}
