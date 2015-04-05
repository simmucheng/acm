#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
__int64 mark;
__int64 x1,x2,x3,x4;
__int64 s[6000];
int mi(__int64 a,__int64 b,__int64 c,__int64 d)
{
    __int64 ma;
    int mark1=0;
    if(a*2<b*3)
      {
          ma=a*2;
          mark=2;
      }
    else {ma=b*3;mark=3;}
    if(ma>c*5)
    {
        ma=c*5;
        mark=5;
    }
    if(ma>d*7)
    {
        ma=d*7;
        mark=7;
    }
    if(ma==a*2)x1++;
    if(ma==3*b)x2++;
    if(ma==5*c)x3++;
    if(ma==7*d)x4++;
    return ma;
}
void init()
{
    for(int l=2;l<5850;l++)
    {
        s[l]=mi(s[x1],s[x2],s[x3],s[x4]);
    }
}
int main()
{
    int i,j,m,n;
    x1=x2=x3=x4=1;
    s[1]=1;
    init();
    while(scanf("%d",&n),n)
    {
        if(n%10==1&&n%100!=11)printf("The %dst humble number is %I64d.\n",n,s[n]);
        //else if(n==11||n==31)printf("The %dth humble number is %I64d.\n",n,s[n]);
        else if(n%10==2&&n%100!=12)printf("The %dnd humble number is %I64d.\n",n,s[n]);
        //else if(n==12)printf("The %dth humble number is %I64d.\n",n,s[n]);
        else if(n%10==3&&n%100!=13)printf("The %drd humble number is %I64d.\n",n,s[n]);
        //else if(n==13)printf("The %dth humble number is %I64d.\n",n,s[n]);
        else
        {
            printf("The %dth humble number is %I64d.\n",n,s[n]);
        }
    }
    return 0;
}
