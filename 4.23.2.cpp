#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define N 0xfffffff
using namespace std;
char s[500010];
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
       scanf("%s",s);
       int mark=0;
       int top=0;
       for(i=0;i<m-1;i++)
       {
           if(s[i]=='.'&&s[i+1]=='#')
           {
               top=i+n;
           }
           if(s[i]=='#'&&s[i+1]=='.')
           {
               if(i+1>top){mark=1;break;}
               top=i+n;
           }
           if(s[i]=='#'&&s[i+1]=='#')
           {
               if(i+1>top){mark=1;break;}
           }
       }
       if(mark==1)printf("NO\n");
       else printf("YES\n");
    }
    return 0;
}
