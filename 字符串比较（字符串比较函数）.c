#include<stdio.h>
#include<string.h>
int main()
{
    char s[6],a[6];//Ϊ��ֻ�ܿ�5���ַ����������Ͳ�����
    gets(s);
    gets(a);
    if(!strcmp(s,a))printf("strings are equal");
    else printf("strings are not equal");
    return 0;
}
