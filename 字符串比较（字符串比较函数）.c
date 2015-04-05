#include<stdio.h>
#include<string.h>
int main()
{
    char s[6],a[6];//为何只能开5个字符，第六个就不行了
    gets(s);
    gets(a);
    if(!strcmp(s,a))printf("strings are equal");
    else printf("strings are not equal");
    return 0;
}
