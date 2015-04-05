#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue<int>ans;
queue<int>wa;
int s[400];
int main()
{
    int m,n,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int mm=m;
        while(!ans.empty())ans.pop();
        while(!wa.empty())wa.pop();
        memset(s,0,sizeof(s));
        for(int ii=1;ii<=k;ii++)
        {
            int x;
            scanf("%d",&x);
            s[x]=1;
        }
        if(k==n){printf("-1\n");continue;}
        for(int ii=1;ii<=n;ii++)
        {
            if(s[ii]==1)ans.push(ii);
            else wa.push(ii);
        }
        int d1=ans.front();
        ans.pop();
        int d2=ans.front();
        ans.pop();
        int bb=wa.front();
        wa.pop();
        printf("%d %d\n",bb,d1);
        printf("%d %d\n",bb,d2);
        m-=2;
        while(!ans.empty()&&m--)
        {
            printf("%d %d\n",d2,ans.front());
            d2=ans.front();
            ans.pop();
        }
        while(m--)
        {
            printf("%d %d\n",d1,wa.front());
            wa.pop();
        }

    }
    return 0;
}
