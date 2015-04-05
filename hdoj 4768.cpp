#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int judge(int ll,int rr,int nn)
{
    for(int ii=1;ii<=nn;ii++)
    {
        int r1=min(rr,s[ii].b);

    }
}
int binary(int ll,int rr,int nn)
{

}
int main()
{
    int n;
    while(scanf("%%d",&n)!=EOF)
    {
        for(int ii=1;ii<=n;ii++)
        {
            scanf("%d%d%d",&s[ii].a,&s[ii].b,&s[ii].c);
            get_ll=min(get_ll,s[ii].a);
            get_rr=max(get_rr,s[ii].b);
        }
        int ans=binary(get_ll,get_rr);
        printf("%d\n",ans);
    }
    return 0;
}

