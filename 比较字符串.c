#include<stdio.h>
#include<string.h>
int main ()
{
    int n;
    char s[100];
    char a[100];
    gets(s);
    gets(a);
    n=strcmp(s,a);
    if(n>0)putchar('>');
    else if(n=0)putchar('=');
    else putchar('<');
    return 0;
}
