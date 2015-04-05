#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 0xfffffff
using namespace std;
char s1[2001000];
char s2[2001000];
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF)
    {
        int a1=0;
        int b1=0;
        int c1=0;
        scanf("%s",s1);
        scanf("%s",s2);
        for(i=0;i<2*n;i++)
        {
            if(s1[i]=='1'&&s2[i]=='1'){c1++;continue;}
            if(s1[i]=='1')a1++;
            if(s2[i]=='1')b1++;
        }
            if(c1%2==1)b1--;
            if(a1>b1)printf("First\n");
            else if((a1==b1)||(a1==b1-1))printf("Draw\n");
            else if(a1<b1-1)printf("Second\n");
    }
    return 0;
}

