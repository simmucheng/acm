#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<cstring>
#define N 0xfffffff
using namespace std;
struct node
{
    int x1;
    int y1;
}s[11010];
struct node1
{
    int aa;
    int bb;
    int mark;
}w[21010<<2];
struct node3
{
    int ll;
    int sta;
}e[11000<<1];
int ss[21011];
int sum;
int cmp(node3 a1,node3 b1)
{
    return a1.ll<b1.ll;
}
void build(int l,int r,int nn)
{
    w[nn].aa=l;
    w[nn].bb=r;
    if(l==r)return ;
    int mid=(l+r)/2;
    build(l,mid,nn<<1);
    build(mid+1,r,(nn<<1)+1);
    return ;
}
void insert(int l,int r,int num,int nn)
{
    int mid=(w[nn].aa+w[nn].bb)/2;
    if(l==w[nn].aa&&r==w[nn].bb) w[nn].mark=num;
    else 
    {
        if(w[nn].mark>0)
        {
            w[nn<<1].mark=w[nn].mark;
            w[(nn<<1)+1].mark=w[nn].mark;
            w[nn].mark=-1;
            /*int uu=w[nn].mark;
            w[nn].mark=-1;
            if(w[nn].aa<l)
            insert(w[nn].aa,l,uu,nn);
            if(w[nn].bb>r)
            insert(r,w[nn].bb,uu,nn);*/
        }//fensan
        if(mid<l)
        {
            insert(l,r,num,(nn<<1)+1);
        }
        else if(mid>=r)
        insert(l,r,num,(nn<<1));
        else 
        {
            insert(l,mid,num,nn<<1);
            insert(mid+1,r,num,(nn<<1)+1);
        }
    }
    return ;
}
void getsum(int nn)
{

    if(w[nn].mark>0)
    {
        if(!ss[w[nn].mark])
        {
           ss[w[nn].mark]=1;
           sum++;  
        }
        return ;
    }
        if(w[nn].aa==w[nn].bb)return ;
        getsum(nn<<1);
        getsum((nn<<1)+1);
    return ;
}
int translate(int nn)
{
    int jj=1;
    int tmp=e[0].ll;
    int top=1;
    for(int ii=0;ii<nn;ii++)
    {
        if(tmp!=e[ii].ll)
        {
            tmp=e[ii].ll;
            top++;
        }
        if(e[ii].sta<0) s[-1*e[ii].sta].x1=top;
        else s[e[ii].sta].y1=top;
    }
    return top-1;
}
void init(int nn)
{
    
    for(int ii=0;ii<=nn;ii++)
    {
        ss[ii]=0;
        e[ii].ll=0;
        e[ii].sta=0;
    }
    memset(w,0,sizeof(w));
    return ;
}

int main()
{
    int i,j,m,n;
    int ma;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;
        ma=-1*N;
        scanf("%d",&m);
        int l=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&s[i].x1,&s[i].y1);
            e[l].sta=-1*i;
            e[l++].ll=s[i].x1;
            e[l].sta=i;
            e[l++].ll=s[i].y1;
        }
        sort(e,e+l,cmp);
        init(translate(l));
        build(1,20100,1);
        for(i=1;i<=m;i++)
        {
            insert(s[i].x1,s[i].y1,i,1);
        }
        getsum(1);
        printf("%d\n",sum);
    }
    return 0;
}
