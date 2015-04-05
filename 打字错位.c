#include<stdio.h>
int main ()
{
    char s[]="`1234567890-=QWERTYUIOP{}|ASDFGHJKL:ZXCVBNM<>?";
    int i,a;
    char c;
    while((c=getchar())!=EOF)
    {
        a=0;
        for(i=0;i<=50;i++)
        {
           if(s[i]==c) putchar(s[i-1]);
            else a++;
         }
        if(a==51) putchar(c);
    }
    return 0;
}
