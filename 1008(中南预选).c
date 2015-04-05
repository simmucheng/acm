#include<stdio.h>
int main()
{
    char s[100][100];
    int i,j,m,n,a,b,x,y,p;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        p=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        scanf("%c",&s[i][j]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i][j]=='W')
        {
            for(x=i-1;x<=i+1;x++)
            {
                for(y=j-1;y<=j+1;y++)
                {
                    if(x==i&&y==j)continue;
                    if(s[x][y]=='W'){i=x;j=y;s[x][y]='.';}
                }
            }
            p++;
        }
    }
    }
    printf("%d\n",p);
    }
    return 0;
}
