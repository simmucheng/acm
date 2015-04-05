#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node2
{
    int nu;
    int sta;
};
int cmp(node2 aa,node2 bb)
{
    return aa.nu<bb.nu;
}
node2 li[101000];
node2 ri[101000];
struct node1
{
    int number;
    int xx;
    int yy;
    int energe;
}s[101000];
struct node
{
    int ll;
    int rr;
    int add;
    int sum;
}w[100100<<2];
void build(int l,int r,int nn)
{
    w[nn].ll=l;
    w[nn].rr=r;
    if(l==r)return ;
    int mid=(l+r)/2;
    build(l,mid);
    build(mid+1,r);
    return ;
}
void insert(int l,int r,int nn,int v)
{
    int mid=(w[nn].ll+w[nn].rr)/2;
    if(l==w[nn].ll&&r==w[nn].rr){w[nn].add+=v;return ;}
    if(r<=mid)insert(l,r,nn<<1);
    else if(mid<l)insert(l,r,(nn<<1)+1);
    else
    {
        insert(l,mid,nn<<1);
        insert(mid,r,(nn<<1)+1);
    }
    return ;
}
int get_sum(int l,int r,int nn)
{
    int num=0;
    int mid=(w[nn].ll+w[nn].r)/2;
    if(w[nn].ll==l&&w[nn].rr==r)
    {
        w[nn].sum+=w[nn].add*(w[nn].r-w[nn].l+1);
        w[nn].add=0;
        num+=w[nn].sum;
        return sum;
    }
    w[nn<<1].add+=w[nn].add;
    w[(nn<<1)+1].add+=w[nn].add;
    w[nn].sum+=(w[nn].rr-w[nn].ll+1)*w[nn].add;
    w[nn].add=0;
    if(r<=mid)num+=get_sum(l,r,nn<<1);
    else if(l>mid)num+=get_sum(l,r,(nn<<1)+1);
    else
    {
        num+=get_sum(l,mid,nn<<1);
        num+=get_sum(mid+1,r,(nn<<1)+1);
    }
    return sum;
}
void lisan()
{
    int temp=li[0];
    for(int ii=0;ii<topx;ii++)
    {
        if(temp!=li[ii].nu)
        {
            ppx++;
            temp=li[ii].nu;
            s[li[ii].sta].xx=ppx;
        }
    }
    int temp=ri[0];
    for(int ii=0;ii<topy;ii++)
    {
        if(temp!=li[ii].nu)
        {
            ppy++;
            temp=ri[ii].nu;
            s[ri[ii].sta].yy=ppy;
        }
    }
    return ;
}
int main()
{
    int i,j,m,n;
    int x,y;
    while(scanf("%d%d%d",&n,&x,&y)!=EOF)
    {
        int topx=0;
        int topy=0;
        for(i=1;i<=n;i++)
        {
            sacnf("%d%d%d",&s[i].xx,&s[i].yy,&s[i].energe);
            li[topx++].nu=s[i].xx;
            ri[topy++].nu=s[i].yy;
        }
        sort(li,li+topx,cmp);
        sort(ri,ri+topy,cmp);
    }
    return 0;
}
