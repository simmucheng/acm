#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[2][10010];
bool judge1(int len)
{
    int flag=0;
    for(int l=0;l<len;l++)
    {
        flag=0;
        for(int k=0;k<len;k++)
        {
            if(s[0][(k+l)%len]!=s[1][k]){flag=1;break;}
        }
        if(!flag)return true;
    }
    return false;
}//shun
bool judge2(int len)
{
   int flag=0;
    for(int l=0;l<len;l++)
    {
        flag=0;
        for(int k=0;k<len;k++)
        {
            if(s[0][((l-k)%len+len)%len]!=s[1][k]){flag=1;break;}
        }
        if(!flag)return true;
    }
    return false;
}//li
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        memset(s[0],0,sizeof(s[0]));
        memset(s[1],0,sizeof(s[1]));
        scanf("%s%s",s[0],s[1]);
        x=strlen(s[0]);
        y=strlen(s[1]);
        if(x!=y)printf("No\n");
        else 
        {
            if(judge1(x)||judge2(x))printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}