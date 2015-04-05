#include<stdio.h>
int main()
{
    char s[20];
    int i,n,m,p=-1,q;
    while(gets(s))
    {
        n=0;
        m=0;
        for(i=0;i<=strlen(s)-1;i++)
        if(s[i]>='0'&&s[i]<='9'){n=1;q=i;break;}
        if(n==0){printf("No\n");}
        if(n==1){
          for(i=0;i<=strlen(s)-1;i++)
               {
                   if(s[i]>='0'&&s[i]<='9')continue;
                   if(s[i]==' '||s[i]=='-'||s[i]=='+'){m=0;p=i;}
                   else {p=100;m=1;break;}
               }
     }
     if(p!=-1)
    {
    if(p<q)printf("Yes\n");
    if(m==1||(p>q))printf("No\n");
    }
    }
    return 0;
}
