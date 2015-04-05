#include<stdio.h>
int main()
{
    long a,b,i,j,m,n,s[100],c;
    while(scanf("%ld",&a)==1){
    s[0]=1;
    for(i=1;i<=a;i++)
    {
        scanf("%ld",&s[i]);
        if(s[i-1]>s[i]){m=s[i-1];n=s[i];}
        else {m=s[i];n=s[i-1];}
        while(1){
        b=m%n;
        m=n;
        n=b;
        if(n==0){s[i]=s[i]/m*s[i-1];
        break;}
    }}
    printf("%ld\n",s[a]);
    }
    return 0;
}
