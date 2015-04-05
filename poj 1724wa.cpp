#include<cstdio>
#include<iostream>
#include<cstring>
#define MA 0xfffffff
using namespace std;
struct node
{
    int len;
    int cost;
}s[110][110];
struct node1
{
    int pre;
    int ne;
}w[11000];
int next[110];
int mark[110];
int c,m;
int ge,top;
void dfs(int nn,int su,int llen)
{
    if(llen>=ge)return ;
    if(nn==m){ge=min(ge,llen);return ;}
    for(int ii=next[nn];ii!=-1;ii=w[ii].ne)
    {
        int kk=w[ii].pre;
        if((!mark[kk])&&(su+s[nn][kk].cost<=c))
        {
            mark[kk]=1;
            dfs(kk,s[nn][kk].cost+su,llen+s[nn][kk].len);
            mark[kk]=0;
        }
    }
    return ;
}
int main()
{
    int i,j,n,k;
    while(scanf("%d",&c)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        memset(next,-1,sizeof(next));
        memset(s,0,sizeof(s));
        ge=MA;
        scanf("%d%d",&m,&n);
        top=0;
        while(n--)
        {
            int aa,bb;
            scanf("%d%d",&aa,&bb);
            scanf("%d%d",&s[aa][bb].len,&s[aa][bb].cost);
            w[top].pre=bb;
            w[top].ne=next[aa];
            next[aa]=top;
            top++;
        }
        dfs(1,0,0);
        if(ge==MA)printf("-1\n");
        else
        printf("%d\n",ge);
    }
    return 0;
}
//ps:可能存在两个点上有多个数据
