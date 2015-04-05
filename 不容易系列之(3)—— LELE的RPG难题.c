#include<stdio.h>
int main()
{
    __int64 s[60];
    int i,j,m,n,a,b;
    s[1]=3;
    s[2]=6;
    s[3]=6;
    while(scanf("%d",&n)==1)
    {
        if(n==1)printf("3\n");
        else if(n==2)printf("6\n");
        else if(n==3)printf("6\n");
        else
        {
            for(i=4;i<=n;i++)
            s[i]=s[i-1]+2*s[i-2];
            printf("%I64d\n",s[n]);
        }
    }
    return 0;
}
