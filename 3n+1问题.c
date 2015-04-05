#include<stdio.h>
int main ()
{
    unsigned int a,i;
    scanf("%d",&a);
    for(i=1;;i++)
    {
        if(a%2==0)
           {
               a=a/2;
           }
        else if(a%2==1)
        {
            a=3*a+1;
        }
        if(a==1)break;
    }
    printf("%u",i);
    return 0;
}
