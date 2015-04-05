#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
/*int cmp(char x,char y)
{
    if(x=='x'&&y=='y')
    return
}*/
int main()
{
    char s[1000100];
    int i;
    while(cin>>s)
    {
        int t=strlen(s);
        int x,y;
        x=0;
        y=0;
             for(i=0;i<t;i++)
             {
                 if(s[i]=='x')x++;
                 else y++;
             }
             if(x-y>0)
             {
                 for(i=0;i<x-y;i++)
                 printf("x");
             }
             else
             {
                 for(i=0;i<y-x;i++)
                 printf("y");
             }
        printf("\n");
        memset(s,0,sizeof(s));
    }
    return 0;
}
