#include<stdio.h>
int main ()
{
    int s[1200]={0};
    int a,i,j;
    scanf("%d",&a);
    for(i=0;i<=a;i++)
    {
        s[i]=i;
    }
    j=a;
    for(i=2;i<=a*a;i+=2)
    {
        j++;
        s[j]=s[i];
        if(s[i-1]!=0) printf("%d ",s[i-1]);
        else break;
    }
    return 0;
}
