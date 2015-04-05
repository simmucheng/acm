#include<stdio.h>
int main()
{
    int a,b,i,j,c=0,n;
    scanf("%d%d",&a,&b);
    while(1)
    {
        n=a%10+b%10+n;
        if(n>9)n=1;
         else n=0;
         c=c+n;
        if(a==0||b==0)
        {
        printf("%d",c);
        break;
        }
        a/=10;
        b/=10;
    }
    return 0;
}
