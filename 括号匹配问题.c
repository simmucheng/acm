#include<stdio.h>
#include<string.h>
int main()
{
    int a,i,j,m,n,k;
    char s[100][100];
    scanf("%d",&a);
    for(i=0;i<a;i++)
    {
        scanf("%s",&s[i]);
    }
    for(i=0;i<a;i++)
    {
        n=0;
        m=0;
        k=0;
        for(j=0;j<strlen(s[i]);j++)
        {
            if(s[i][j]=='(')n++;
            if(s[i][j]==')')m++;
            if((n-m)<0){k=1;break;}
        }
        if(k==1){
            putchar('0');
            putchar('\n');
            continue;}
        if(m==n)putchar('1');
        else putchar('0');
        putchar('\n');
    }
    return 0;
}
