#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
char w[210];
char getans[210];
struct node
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
        getchar();
        gets(w);
        int top=0;
        for(i=1;i<=n;i++)
        {
            while(!mark[i])
            {
                ee[top].push_back(s[i]);
                mark[i]=1;
                i=s[i].num;
            }
            int nn=ee[top].size();
            for(j=0;j<nn;j++)
            {
                ans[ee[top][j].sta]=ee[top][(j+m)%nn].num;
            }
            top++;
        }
        for(i=1;i<=n;i++)
        cout<<ans[i]<<endl;
        int mm=strlen(w);
        for(i=1;i<=n;i++)
        {
            if(n-1>mm)
            getans[ans[i]-1]=' ';
            else
            getans[ans[i]-1]=w[ans[i]-1];
        }
        puts(getans);
        printf("\n\n");
    }
    return 0;
}
