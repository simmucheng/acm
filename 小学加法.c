#include<stdio.h>
int main ()
{
    int a,b,s[10]={0},i,j,c,n=0;
    scanf("%d%d",&a,&b);
    for(i=9;i>=0;i--)
    {
       n=a%10+b%10+n;
       if(n>9)
       {
            s[i]=n-10;
            n=1;
       }
       else
       {
             s[i]=n;
             n=0;
       }
       a/=10;
       b/=10;
    }

    for(i=0;i<=9;i++)
    {
        c=0;
        if(s[i]>0){
            c=1;
        for(j=i;j<=9;j++)printf("%d",s[j]);
                  }
        if(c==1)break;
    }
    return 0;
}
