#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        int ee=0;
        while(n--)
        {
            char s[20];
            int a,c;
            char b,d;
            scanf("%d%c%d",&a,&b,&c);
            scanf("%c",&d);
            gets(s);
            if(s[0]!=' ')
            {
                int mi=strlen(s);
                int sum=0;
                int nn=1;
                for(i=mi-1;i>=0;i--)
                {
                    sum+=(s[i]-'0')*nn;
                    nn*=10;
                }
                if(b=='+'&&(a+c)==sum)ee++;
                else if(b=='-'&&(a-c)==sum)ee++;
                else if(b=='*'&&(a*c)==sum)ee++;
                else if(b=='/'&&(a/c)==sum)ee++;
            }
        }
        printf("%d\n",ee);
    }
    return 0;
}
