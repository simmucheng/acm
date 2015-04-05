#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node
{
    int x;
    int y;
    int mark;
    int ste;
}s[12][12];
int main()
{
    int i,j,m,n,sta;
    while(cin>>m>>n>>sta,m||n||sta)
    {
        memset(s,0,sizeof(s));
        node r;
        char e;
        r.x=1;
        r.y=sta;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin>>e;
                if(e=='S'){s[i][j].x=1;s[i][j].y=0;}
                else if(e=='N'){s[i][j].x=-1;s[i][j].y=0;}
                else if(e=='W'){s[i][j].x=0;s[i][j].y=-1;}
                else if(e=='E'){s[i][j].x=0;s[i][j].y=1;}
            }
        }
        int step=0;
        int mm=0;
        while((r.x>0)&&(r.x<m+1)&&(r.y>0)&&(r.y<n+1))
        {
            int x1=r.x;
            int y1=r.y;
            step++;
            if(s[r.x][r.y].mark==1){mm=1;break;}
            s[r.x][r.y].mark=1;
            s[r.x][r.y].ste=step;
            r.x+=s[x1][y1].x;
            r.y+=s[x1][y1].y;

        }
        if(mm==0)printf("%d step(s) to exit\n",step);
        else printf("%d step(s) before a loop of %d step(s)\n",s[r.x][r.y].ste-1,step-s[r.x][r.y].ste);
    }
    return 0;
}
