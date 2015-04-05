#include<iostream>
#include<cmath>
#include<algorithm>
#include<stack>
#include<fstream>
using namespace std;
struct node
{
    int x;
    int y;
}s[50010];
node w[50010];
int cmp(node a,node b)
{
    if((a.y-s[0].y)*(b.x-s[0].x)!=(a.x-s[0].x)*(b.y-s[0].y))
    return (s[0].y-b.y)*(s[0].x-a.x)>(s[0].x-b.x)*(s[0].y-a.y);
    else
    return a.x<b.x;
}
int judge(node a,node b,node c)
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int distence(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int abb(int e)
{
    if(e<0)return -e;
    else return e;
}
int findmax(int h)
{
    h++;
    int ma=0;
    int p,q;
    q=1;
    w[h]=w[0];
    for(p=0;p<h;p++)
    {
        while(abb(judge(w[p],w[q],w[p+1]))<abb(judge(w[p],w[q+1],w[p+1])))q=(q+1)%h;
        //cout<<"p = "<<p<<"   "<<"q = "<<q<<distence(w[p],w[q])<<' '<<distence(w[p+1],w[q])<<endl;
        ma=max(ma,max(distence(w[p],w[q]),distence(w[p+1],w[q])));
    }
    return ma;
}
/*int findmax2(int h)
{
    int ii,jj;
    int ma=-0xffffff;
    for(ii=0;ii<h+1;ii++)
    {
        for(jj=ii;jj<h+1;jj++)
            ma=max(ma,distence(w[ii],w[jj]));
    }
    return ma;
}// O(n^2)*/
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    int x1=0xfffffff;
    int y1=0xfffffff;
    int mark;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&s[i].x,&s[i].y);
        if((x1>s[i].x)||(x1==s[i].x&&y1>s[i].y))
        {
            x1=s[i].x;
            y1=s[i].y;
            mark=i;
        }
    }
    swap(s[0],s[mark]);
    sort(s+1,s+n,cmp);
    int k=0;
    int l;
    l=1;
    w[0]=s[0];
    w[1]=s[1];
    for(i=2;i<n;i++)
    {
        if(l<1)w[++l]=s[i];
        while(l>0)
        {
            if(judge(w[l-1],w[l],s[i])<0)--l;
            else {w[++l]=s[i];break;}
        }
    }
    int uu=findmax(l);
    printf("%d\n",uu);
    return 0;
}
