#include<stdio.h>
int main()
{
    int a,i,n,c;
    while( scanf("%d",&a)==1)
    {
    for(i=1;;i++)
    {
        if(i*(i+1)>=2*a&&i*(i-1)<=2*a)
        {

            c=a-i*(i-1)/2;
            break;
        }
    }
    if(i%2==0)
    printf("%d/%d\n",c,i+1-c);
    else printf("%d/%d\n",i+1-c,c);
    }
    return 0;
}
