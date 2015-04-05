#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    int i,j,m,n;
    char s[100];
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int mark=0;
        if(m<0){printf("-");m=-1*m;}
        itoa(m,s,n);
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]<='f'&&s[i]>='a')printf("%c",s[i]-'a'+'A');
            else printf("%c",s[i]);
        }
        cout<<endl;
    }
    return 0;
}
