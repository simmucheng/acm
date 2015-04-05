#include<stdio.h>
int main()
{
    int i,j,m,n,a,c;
    scanf("%d",&a);
    while(a--)
{
        scanf("%d",&n);
            m=n/200+1;
            c=n;
    for(i=0;i<m;i++)
    {
       c=c<(n-(200*i))%150?c:(n-(200*i))%150;
    }
    printf("%d\n",c);
}
    return 0;
}
