#include<stdio.h>
#include<string.h>
int main ()
{
    char s[100],a[100],c[100];
    int b,i,j,n,k,h,m=0,p,q,z;
    scanf("%d",&b);
    for(i=1;i<=b;i++)
    {
    gets(s);
    gets(a);
    gets(c);
    //puts(c);
    n=strlen(a)-strlen(c);
    p=strlen(a);
    q=strlen(c);
    z=strlen(s);
    for(i=0;i<strlen(s);i++)
    {
        if(a[0]==s[i])
        {
            for(j=1;j<strlen(a);j++)
            {
                if(s[i+j]!=a[j])break;
                else m=1;
            }
        }
    }
    if(m==1)
    {
        for(k=0;k<strlen(c);k++)
        {
            s[i+k]=c[k];
        }
        if(n>0){
        h=0;
        for(k=1;k<n;k++)
        {
            s[i+q+k]=s[i+p+k];
        }
         s[z-n]='\0';
        }
    }
    }
    puts(s);
    return 0;
}
