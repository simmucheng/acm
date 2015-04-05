#include<iostream>
#include<cstdio>
using namespace std;
char s[1000010];
int dj(int x,int y)
{
    int w=(y-x)/2+x-1;
    for(int l=x-1;l<w;l++)
    {
        if(s[l]!=s[y-1-l])return 0;
    }
    return 1;
}
int main()
{
    int i,j,m,n;
   // char s[1000010];
    char t,c;
    while(scanf("%s",s)!=EOF)
    {
        cin>>n;
        while(n--)
        {
            cin>>t;
            if(t=='C')
            {
              cin>>m>>c;
              s[m-1]=c;
            }
            else
            {
                int x,y;
                scanf("%d%d",&x,&y);
                int u=dj(x,y);
                if(u==1)printf("yes\n");
                else printf("no\n");
            }
        }
    }
    return 0;
}

