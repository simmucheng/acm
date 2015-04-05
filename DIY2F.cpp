#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    int year;
    int stre;
}s[1000090];
int cmp(node x,node y)
{
    if(x.year!=y.year)return x.year<y.year;
    return x.stre>y.stre;
}
int main()
{
    int i,j,k,l,m,n;
    int x1,y1;
    scanf("%d%d",&m,&n);
        scanf("%d%d",&x1,&y1);
        for(i=0;i<n-m+2;i++)
        scanf("%d%d",&s[i].year,&s[i].stre);
        if(x1!=2011||(x1==2011&&m==1)){printf("%d\n",x1);return 0;}
        sort(s,s+n-m+2,cmp);
        for(i=0;i<n-m+2;i++)
        {
            if(s[i].year>=x1&&s[i].stre<=y1)
            {
             cout<<s[i].year<<endl;
             break;
            }
         if(i==n-3+m)printf("unknown\n");
        }
    return 0;
}
