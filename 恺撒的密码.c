#include<stdio.h>
#include<string.h>
int main()
{
    char s[1002];
    int i=0;
    int n,m;
    scanf("%d",&m);
    getchar();
    while(m--)
    {
        gets(s);
        n=strlen(s);
             for(i=0;i<n;i++)
             {
                 if(s[i]>='A'&&s[i]<='E')s[i]=s[i]+ 21;
                 else if(s[i]>'E'&&s[i]<='Z')s[i]=s[i]-5;
             }
        puts(s);
    }
    return 0;
}
