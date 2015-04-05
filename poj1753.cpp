#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int s[4];
int mi=0xffffff;
int in[4][2]={1,0,0,1,-1,0,0,-1};
void DFS(int x,int y,int ci,int a1,int a2,int a3,int a4)
{
    int w[4];
    w[0]=a1;
    w[1]=a2;
    w[2]=a3;
    w[3]=a4;
    if(w[0]+w[1]+w[2]+w[3]==0||(w[0]+w[1]+w[2]+w[3]==60))mi=min(ci,mi);
    if(x>3||y>3)return ;
    if(y==3)DFS(x+1,0,ci,w[0],w[1],w[2],w[3]);
    else DFS(x,y+1,ci,w[0],w[1],w[2],w[3]);
        w[x]=w[x]^(1<<(3-y));
        for(int l=0;l<4;l++)
        {
            int x1=x+in[l][0];
            int y1=y+in[l][1];
            if(x1<4&&x1>=0&&y1<4&&y1>=0)
            w[x1]=w[x1]^(1<<(3-y1));
        }
        ++ci;
        if(y==3)DFS(x+1,0,ci,w[0],w[1],w[2],w[3]);
        else DFS(x,y+1,ci,w[0],w[1],w[2],w[3]);
}
int main()
{
    int i,j,m,n;
    char t;
        memset(s,0,sizeof(s));
        mi=0xffffff;
        for(i=0;i<4;i++)
        {
          for(j=0;j<4;j++)
             {
             scanf("%c",&t);
             if(t=='b')s[i]+=(int)pow(2*1.0,(3.0-j*1.0));
             }
             getchar();
        }
       DFS(0,0,0,s[0],s[1],s[2],s[3]);
       if (mi==0xffffff)printf("Impossible\n");
       else printf("%d\n",mi);
    return 0;
}
