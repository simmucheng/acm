#include<stdio.h>
#include<string.h>
int main()
{
    int i,n,j;
    char a,s[100];
    gets(s);
    scanf("%c",&a);
    for(i=0;i<=strlen(s)-1;i++)
    {
        if(a==s[i])
        {
            for(j=i;j<strlen(s)-1;j++)
            {
                s[j]=s[j+1];
            }
            n=strlen(s)-1;
            s[n]='\0';
        }
    }
    puts(s);
    return 0;
}
