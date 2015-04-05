#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
char w[210];
node
{
    int num;
    int sta;
}s[210];
int ans[210];
int mark[210];
vector<node> ee[210];
void init()
{
    memset(mark,0,sizeof(mark));
    for(int ii=0;ii<=200;ii++)
    ee[ii].clear();
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i].num);
            s[i].sta=i;
        }
        scanf("%d",&m);
        gets(w);
        int top=0;
        for(i=1;i<=n;i++)
        {
            while(!mark[i])
            {
                ee[top].push(s[i]);
                mark[i]=1;
                i=s[i].num;
            }
            int nn=ee[top].size();
            for(j=0;j<nn;j++)
            {
                ans[ee[top][j].sta]=ee[top][(j+k)%nn];
            }
            top++;
        }
        int mm=strlen(s);
        for(i=1;i<=n;i++)
        {
            if(n-1>mm)
            printf(" ");
            else
            printf("%c",s[ans[i]-1]);
        }
        printf("\n");
    }
    return 0;
}
