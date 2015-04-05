#include<stdio.h>
#include<string.h>
int main()
{
    char s[100];
    int i,j,a=0,b=0,m=0,k,n=0;
    gets(s);
    for(j=1;j<=(strlen(s)-1);j++)
    {
        if(s[0]==s[j])
        {
            for(i=0;i<=(j-1);i++)
            {
            if(s[i]==s[j+i])
            a++;
        }}
        if(a==j)
        {
            n=1;
            break;
        }
    }
    for(i=j;i<=(strlen(s)-1);i+=j)
    {
        b=0;
        for(k=0;k<=j-1;k++)
        {if(s[k]==s[i+k])
        b++;
        }
        if(b==j)
        {
            n++;
        }
        else m++;
    }
    if(m>0)putchar('1');
    else if(n==0)putchar('1');
    else printf("%d",n);
    return 0;
}
