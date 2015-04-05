#include<stdio.h>
#include<string.h>
long s[1000001];
int main()
{
   long a,b,m,n,i,j,k,c;
   while(scanf("%ld%ld",&a,&b)==2){
     memset(s,0,sizeof(s));
     m=0;
    for(i=0;i<a;i++)
    {
        scanf("%ld",&c);
        k=500000+c;
        s[k]=1;
    }
    for(i=1000000;;i--)
    {
        if(s[i]){
            m++;
        if(m>b)break;
        else if(m==b)printf("%d\n",i-500000);
        else printf("%d ",i-500000);
        }
    }
}
    return 0;
}

