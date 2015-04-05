#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<iostream>
using namespace std;
const int MAXN=1e5+10000;
struct node
{
    int l;
    int r;
    int value;
}tree[MAXN<<2];
int m,n,k,ans,s[MAXN];
void build(int ll,int rr,int nn)
{
    tree[nn].l=ll;
    tree[nn].r=rr;
    if(ll==rr)return ;
    int mid=(tree[nn].l+tree[nn].r)>>1;
    build(ll,mid,nn<<1);
    build(mid+1,rr,(nn<<1)+1);
    return ;
}
void inser(int ll,int rr,int nn,int vv)
{
    if(tree[nn].l==ll&&tree[nn].r==rr){tree[nn].value+=vv;return ;}
    int mid=(tree[nn].l+tree[nn].r)>>1;

    inser(tree[nn].l,mid,nn<<1,tree[nn].value);
    inser(mid+1,tree[nn].r,(nn<<1)+1,tree[nn].value);

    if(rr<=mid)inser(ll,rr,nn<<1,vv);
    else if(ll>mid)inser(ll,rr,(nn<<1)+1,vv);
    else
    {
        inser(ll,mid,nn<<1,vv);
        inser(mid+1,rr,(nn<<1)+1,vv);
    }
    tree[nn].value=0;
    return ;
}

void fin(int nn,int vv)
{
    if(tree[nn].l==tree[nn].r&&tree[nn].value+vv>=k)ans++;
    else if(tree[nn].l==tree[nn].r)return ;
    else
    {
        fin(nn<<1,vv+tree[nn].value);
        fin((nn<<1)+1,vv+tree[nn].value);
    }
    return ;
}
int binary(int nn)
{
    int ll=1;
    int rr=n;
    while(ll<rr)
    {
        //cout<<"ll = "<<ll<<' '<<"rr = "<<rr<<endl;

        int mid=(ll+rr)>>1;//cout<<s[mid]<<' '<<nn<<" mid = "<<mid<<endl;
        if(nn>s[mid])ll=mid+1;
        else rr=mid;
    }
    return ll;
}
int main()
{
    int sta=1;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        ans=0;
        memset(tree,0,sizeof(tree));
        for(int ii=1;ii<=n;ii++)scanf("%d",&s[ii]);
        sort(s+1,s+n+1);
        build(1,n,1);
        int sy=1;
        for(int ii=0;ii<m;ii++)
        {
            int x,y,stax,stay;
            scanf("%d%d",&x,&y);
            if(sy>=s[n]){sy=y;continue;}
            stax=binary(sy+1);
            if(x>=s[n])stay=n;
            else stay=binary(x+1)-1;
            if(stay<stax||stay<0){sy=y;continue;}
            //cout<<"fuck = "<<stax<<' '<<stay<<endl;
            inser(stax,stay,1,1);
            sy=y;
        }
        fin(1,0);
        printf("Case %d: %d\n",sta++,ans);
    }
    return 0;
}
