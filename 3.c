#include<stdio.h>
#include<stdlib.h>
#include<string.h>
    int i,j,m,n;
    char o[110][110];
    int sc[8]={-1,0,1,-1,1,-1,0,1};
    int sr[8]={1,1,1,0,0,-1,-1,-1};
    int mon;
    void bfs(int a,int b)
    {
        int q1,q2,l;
        o[a][b]='*';
            for(l=0;l<8;l++)
            {
                q1=a+sc[l];
                q2=b+sr[l];
                if(o[q1][q2]!='@')continue;
                bfs(q1,q2);
            }
    }
int main()
    {
        int k1,k2;
        while(scanf("%d%d",&m,&n)&&m)
        {
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
                     bfs(i,j);
                    }
                }
            }
            printf("%d\n",mon);
        }
        return 0;
    }
