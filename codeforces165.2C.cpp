#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
    int len;
    int num;
}s[100100];
int cmp(node x,node y)
{
    if(x.len!=y.len)
    return x.len<y.len;
}
int main()
{
    int i,j,m,n;
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        scanf("%d%d",&s[i].len,&s[i].num);
        sort(s,s+n,cmp);
        double rr=s[n-1].num*1.0;
        int mark=0;
       /* while(rr>1)
        {
            mark++;
            rr/=4;
        }*/
        int ll=s[n-1].len+1;
        int y=0;
        for(i=n-1;i>=0;i--)
        {
            int ee=ll-s[i].len;
            if(pow(4.0,(ee+y)*1.0)<s[i].num){y++;i++;}
        }
        printf("%d\n",ll+y);
    }
    return 0;
}
