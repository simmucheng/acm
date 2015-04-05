#include<stdio.h>
int main()
{
   int a,b,y,i,j,T,x,s[600],k;
   long n,m;
   while(scanf("%d%d%ld",&a,&b,&n)==3)
   {
       k=0;
    if(n==0&&a==0&&b==0)break;
   s[1]=1;
   s[2]=1;
   for(i=3;;i++)
   {
       s[i]=((a%7)*s[i-1]+(b%7)*s[i-2])%7;
       for(j=2;j<i;j++)
       if((s[j]==s[i])&&(s[j-1]==s[i-1])){k=1;break;}
        if(k==1)break;
   }
    T=i-j;
        if(n<i)printf("%d\n",s[n]);
    else {
        m=(n-j+1)%T;
   if(m==0)printf("%d\n",s[j-1+T]);
   else printf("%d\n",s[m+j-1]);
   }
   }
   return 0;
}
