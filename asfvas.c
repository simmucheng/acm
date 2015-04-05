#include<stdio.h>
#include<math.h>
#include<stdlib.h>
__int64 cm(__int64 z)
{
    while(z%2==0)
    {
        z/=2;
    }
    return z;
}
int main()
{
    __int64 i,j,p,n;
    __int64 a;
    a=pow(10,18)-1;
    scanf("%I64d",&p);
    for(i=1;i<=p;i++)
    {
        __int64 ma=1;
        scanf("%I64d",&n);
        printf("Case %I64d: ",i);
        if(n<0){ma=-1;n=-1*n;}
        else if(n==0){printf("face : %I64d figure : 0\n",a);continue;};
        if(n%2==1)printf("illegal score.\n");
        else
        {
            __int64 u=cm(n);
            printf("face : %I64d figure : %I64d\n",u,(n/u)*ma);
        }
    }
    return 0;
}

