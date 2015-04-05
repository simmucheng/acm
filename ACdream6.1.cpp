#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int a;
    int b;
    double s;
};
int cmp(node x,node y)
{
    if(x.s!=y.s)
    return x.s>y.s;
}
int main()
{
    int i,j,m,n,k;
    node w[1010];
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        scanf("%d",&w[i].a);
        for(i=0;i<n;i++)
        {
            scanf("%d",&w[i].b);
            w[i].s=w[i].a/w[i].b;
        }
        sort(w,w+n,cmp);
        double r1=1;
        double r2=1;
        for(i=0;i<k;i++)
        {
            r1*=w[i].a;
            r2*=w[i].b;
        }
        double t=log(r1-r2);
        printf("%.3f\n",t);
    }
    return 0;
}
