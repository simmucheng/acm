#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
queue<int>qx,qy;
int w[4][2]={0,1,0,-1,1,0,-1,0};
int bfs(int a,int b)
{
    qx.push(a);
    qy.push(b);
    int x,y;
    if(!qx.empty())
    {
        x=qx.front();qx.pop();
        y=qy.front();qy.pop();
        for(int l=0;l<4;l++)
        {
        if(s[x][y]>s[x+s[l][0]][y+s[l][1]])
        {qx.push(x+s[l][0]);qy.push(y+s[l][1]);}
        }
    }
}
int main()
{
    int i,j,m,n;
    int s[110][110];
    cin>>m>>n;
    for(i=0;i<m;m++)
    {
        for(j=0;j<n;j++)
        cin>>s[i][j];
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(s[i][j]!=-1)
            {
                bfs(i,j);
            }
        }
    }

}
