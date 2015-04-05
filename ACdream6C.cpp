#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
map<int,int>q;
int main()
{
    int i,j,m,n;
    int s[110][110];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            scanf("%d",&s[i][j]);
        }
        int ma=0;
        int w=0;
        scanf("%d",&m);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j==m)continue;
                for(int k=1;k<=n;k++)
                {
                    if(k==i)continue;
                    if(s[m][i]>s[j][k])q[j]++;
                }
            }
                int mark=0;
                for(int l=n-1;l>=1;l--)
                {
                    int er=0;
                    for(int r=1;r<=n;r++)
                    {
                        if(r==m)continue;
                        if(q[r]>=l){q[r]=0;er=1;break;}
                    }
                   if(er==0){mark=1;break;}
                }
            if(mark==0&&w>0){printf(" %d",i);ma=1;}
            else if(mark==0&&w==0){printf("%d",i);ma=1;w=1;}
            q.clear();
        }
        if(ma==0)printf("-1");
        printf("\n");
    }
    return 0;
}
