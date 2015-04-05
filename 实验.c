#include<stdio.h>
int main ()
{
    int i,a=0,s[1200];
    for(i=1;i<=1200;i++)
    {
    scanf("%d",&s[i]);
    a+=s[i];

    }
    printf("%d",a/i);
    printf("Yes");
    return 0;
}
