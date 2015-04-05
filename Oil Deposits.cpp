#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    int i,j,m,n;
    char o[110][110];
    int p[110][110];
    int sc[8]={-1,0,1,-1,1,-1,0,1};
    int sr[8]={1,1,1,0,0,-1,-1,-1};
    int mon;
    void bfs(int a,int b)
    {
        int q1,q2,l;
        o[a][b]='*';
        p[a][b]=mon;
            for(l=0;l<8;l++)
            {
                q1=a+sc[l];
                q2=b+sr[l];
                if(p[q1][q2]||o[q1][q2]!='@')continue;
                dfs(q1,q2);
            }
    }
int main()
    {
        int k1,k2;
        while(scanf("%d%d",&m,&n)&&m)
        {
           memset(o,'*',sizeof(o));
            memset(p,0,sizeof(p));
            mon=0;
            getchar();
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    scanf("%c",&o[i][j]);
                }
                getchar();
            }
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(o[i][j]=='@')
                    {
                     mon++;
                     dfs(i,j);
                    }
                }
            }
            printf("%d\n",mon);
        }
        return 0;
    }
