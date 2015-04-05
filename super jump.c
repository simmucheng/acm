#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,i,j,a,b,t,d;
    int s[1020],x[1020];
    while(scanf("%d",&n)==1)
    {
        memset(s,0,sizeof(s));
        memset(x,0,sizeof(x));
        if(n==0)continue;
        else {
        for(i=0;i<n;i++)
            scanf("%d",&s[i]);
        x[0]=s[0];
        d=0;
        for(i=0;i<n;i++)
        {
            t=0;
            for(j=0;j<i;j++)
            {if(s[j]<s[i])t=t>x[j]?t:x[j];
            x[i]=t+s[i];
            d=d>x[i]?d:x[i];}
        }
        printf("%d\n",d);
    }
    }
    return 0;
}
