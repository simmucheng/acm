#include<stdio.h>
#include<string.h>
#define N 100+10
int s[N],b[N];
int main()
{
    int i,a,n=0;
   while(scanf("%d",&a)==1)
   s[n++]=a;
    memcpy(b,s,sizeof(s));
    for(i=n-1;i>=0;i--)
        printf("%d\n",b[i]);
    return 0;
}
