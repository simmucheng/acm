#include<stdio.h>
#include<string.h>
int s[16][16];
int h[16][16];
int con,a,b,m,n,d1,d2;
void dfs(int x,int y)
{
    int l;
    int w[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    h[x][y]=1;
    if(x==1||x==m||y==1||y==n)
        con++;
    for(l=0;l<4;l++)
        {
            d1=x+w[l][0];
            d2=y+w[l][1];
            if(s[d1][d2]>=s[x][y]&&h[d1][d2]==0&&d1>0&&d2>0&&d1<m+1&&d2<n+1)
                        dfs(d1,d2);
        }
}
int main()
{
    int c,d,i,j,e,k;
        scanf("%d",&e);
    for(k=1;k<=e;k++)
    {
        con=0;
        scanf("%d%d",&m,&n);
        scanf("%d%d",&a,&b);
        memset(h,0,sizeof(h));
        for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        scanf("%d",&s[i][j]);
        dfs(a,b);
        printf("Case #%d: %d\n",k,con);
    }
    return 0;
}
