#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
    int p;
    int b;
};
int main()
{
    int i,j,m,n,p;
    __int64 P,B;
    node s[110][110];
    node dp[110][110];
    int f[110];
    scanf("%d",&n);
    while(n--)
    {
        double w=0.0;
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>f[i];
            for(j=0;j<f[i];j++)
            cin>>s[i][j].b>>s[i][j].p;
        }
        double  e=0.0;
        int mi=0xfffff;
        int x=0xfffff;
        int y;
        for(i=0;i<m;i++)
        {
            y=0;
            for(j=0;j<f[i];j++)
              {
                  y=max(y,s[i][j].b);
                  x=min(x,s[i][j].b);
              }
            mi=min(mi,y);
        }
        int k;
        for(k=x;k<=mi;k++)
        {
            int r=0;
          int num=0;
          int mark=0;
          for(i=0;i<m;i++)
           {
             int e=0xffffff;
             for(j=0;j<f[i];j++)
              {
                if(s[i][j].b>=k)
                   {
                       mark=1;
                       e=min(e,s[i][j].p);
                   }
              }
             if(mark==0){r=1;break;}
             if(e==0xffffff){r=1;break;}
             num+=e;
           }
           if(r==1)continue;
           double q=k*1.0/num;
           w=q>w?q:w;
        }
        printf("%.3f\n",w);
    }
    return 0;
}
