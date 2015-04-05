#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int i,j,m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(m<n*3)printf("-1\n");
        else
        {
            int t=m/n;
            int u=1;
            for(i=1;i<=(t-1)*n;i++)
            {
                printf("%d ",u);
                if(i%(t-1)==0)u++;
            }
            u=1;
            for(i=(t-1)*n+1;i<=t*n;i++)
            printf("%d ",u++);
            for(i=t*n+1;i<=m;i++)
            {
                if(i==m){printf("%d\n",n);break;}
                printf("%d ",n);
            }
        }
    }
    return 0;
}
