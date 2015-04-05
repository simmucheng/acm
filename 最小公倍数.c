#include<stdio.h>
#include<math.h>
int main ()
{
    int a,b,c,d,r;
    scanf("%d%d",&a,&b);
    if(a>b){c=a;a=b;b=c;}
    /*while(c%a!=0||c%b!=0)
    c++;
    printf("%d",c);
    return 0;*/
    while(1)
    {
    c=b%a;
    b=a;
    a=c;
    if(a==0)break;
    }
    printf("%d",b);
    return 0;
}
