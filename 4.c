#include<stdio.h>
#include<string.h>
#define M 111
int a[M][M];
char s[M][M];
int dx[]={-1,0,1,-1,1,-1,0,1};
int dy[]={1,1,1,0,0,-1,-1,-1};
int num;
void BFS(int i,int j)
{
    int i1,j1,k;
    a[i][j]=num;
    s[i][j]='!';
    for(k=0;k<8;k++)
    {
        i1=i+dx[k];
        j1=j+dy[k];
        if(a[i1][j1]||s[i1][j1]!='@')continue;
        BFS(i1,j1);
    }
}
int main()
{
    int m,n,i,j;
    while(scanf("%d%d",&m,&n)&&m)
    {
        num=0;
        memset(a,0,sizeof(a));
        for(i=0;i<m;i++)
        scanf("%s",s[i]);
        for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        if(s[i][j]=='@')
        {
            num++;
            BFS(i,j);
        }
        printf("%d\n",num);
        /*for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            printf("%d",a[i][j]);
            printf("\n");
        }*/
    }
    return 0;
}
