#include<stdio.h>
#include<string.h>
#define N 3000
int main ()
{
    int a,b,s[N]={0},i,j,m,c=0,n;
    scanf("%d",&m);
    s[0]=1;
    for(i=2;i<=m;i++)
    {
        n=0;
        for(j=0;j<3000;j++)
        {
            s[j]=n+s[j]*i;
            n=s[j]/10;
            s[j]=s[j]%10;
        }
    }

    for(i=2999;i>=0;i--)
    {
        if(s[i]>0)
        {
            c=1;
            for(j=i;j>=0;j--)
            printf("%d",s[j]);
        }
        if(c==1)break;
    }
    return 0;
}
