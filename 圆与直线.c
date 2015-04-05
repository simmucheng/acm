#include<stdio.h>
int main()
{
    int a,i,n;
    while(scanf("%d",&a)==1)
    {
    if(a==-1)break;
    n=1;
        for(i=1;i<=a;i++)
           {
              n+=i;
           }
    printf("%d\n",n);
    }
    return 0;
}
