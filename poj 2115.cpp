#include<iostream>
#include<cstdio>
using namespace std;
__int64 EUCLID(__int64 a,__int64 b,__int64 &x,__int64 &y)
{
	if(b==0){x=1;y=0;return a;}
	__int64 d=EUCLID(b,a%b,x,y);
	__int64 xt=x;
	x=y;
	y=xt-(a/b)*y;
    return d;
}
int main()
{
    __int64 x1,x2,x3,x4;
    while(scanf("%I64d%I64d%I64d%I64d",&x1,&x2,&x3,&x4),x1||x2||x3||x4)
    {
    	__int64 aa=1;
       __int64 num=aa<<x4;
        __int64 a=x2-x1;
        __int64 x,y;
        __int64 d=EUCLID(x3,num,x,y);
        if(a%d)printf("FOREVER\n");
        else 
        {
        	__int64 x1=(x*(a/d))%num;
        	x1=(x1%(num/d)+(num/d))%(num/d);
        	printf("%I64d\n",x1); 
        }
    }
    return 0;
}