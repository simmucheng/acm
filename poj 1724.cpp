#include<cstdio>
#include<iostream>
#include<cstring>
#define MA 0xfffffff
using namespace std;
struct node
{
    int len;
    int cost;
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
        if((!mark[kk])&&(su+w[ii].cost<=c))
        {
            mark[kk]=1;
            dfs(kk,w[ii].cost+su,llen+w[ii].len);
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
        ge=MA;
        scanf("%d%d",&m,&n);
        top=0;
        while(n--)
        {
            int aa,bb;
            scanf("%d%d",&aa,&bb);
            scanf("%d%d",&w[top].len,&w[top].cost);
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
