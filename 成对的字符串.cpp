#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    char s[1100];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",s);
        int t=strlen(s);
        int mark=0;
        for(i=0;i<strlen(s);i++)
        {
            for(j=t-1;j>=0;j--)
            {
                if(i==j){mark=1;break;}
                if(s[i]==s[j]){t=j;break;}
            }
            if(mark==1)break;
        }
        if(mark==1&&(i+1)*2==strlen(s))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
