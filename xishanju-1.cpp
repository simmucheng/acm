#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
char s[2][1010];
int w[30][110];
int sta[30];
int r1[30],r2[30];
int main()
{
    int i,j,m,n,k;
    scanf("%d",&n);
    for(k=1;k<=n;k++)
    {
        memset(w,-1,sizeof(w));
        memset(r1,0,sizeof(r1));
        memset(r2,0,sizeof(r2));
        memset(s,0,sizeof(s));
        memset(sta,0,sizeof(sta));
        scanf("%s",&s[0]);
        scanf("%s",&s[1]);
        scanf("%d",&m);
        while(m--)
        {
            char x[2],y[2];
            scanf("%s%s",&x,&y);
            w[x[0]-'a'][++sta[x[0]-'a']]=y[0]-'a';
        }
        int x1=strlen(s[0]);
        int x2=strlen(s[1]);
        int top=0;
        for(i=0;i<x2;i++)
        {
           int mark=0;
           if(s[1][i]!=s[0][top])
           {
               for(j=1;j<=sta[s[1][i]-'a'];j++)
               {
                   if(s[0][top]-'a'==w[s[1][i]-'a'][j])
                    {
                        mark=1;top++;break;
                    }
               }
           }
           else top++;
        }
        printf("Case #%d: ",k);
        if(top==x1)printf("happy\n");
        else printf("unhappy\n");
    }
    return 0;
}
