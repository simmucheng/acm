#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node
{
    int x;
    int y;
};
node sm[18];
int step;
int s[4];
int mark=0;
bool DFS(int x,int y,int ci,int a1,int a2,int a3,int a4)
{
    if(mark==1)return 1;
    int w[4];
    w[0]=a1;
    w[1]=a2;
    w[2]=a3;
    w[3]=a4;
    if(w[0]+w[1]+w[2]+w[3]==60&&step==ci){mark=1;return true;}
    if(w[0]+w[1]+w[2]+w[3]!=60&&step==ci)return 0;
    if(x>3)return false;
    if(y==3)DFS(x+1,0,ci,w[0],w[1],w[2],w[3]);
    else DFS(x,y+1,ci,w[0],w[1],w[2],w[3]);
    if(mark==1)return 1;
        w[x]=w[x]^15;
        for(int e=0;e<4;e++)
           {
               if(e==x)continue;
               w[e]=w[e]^(1<<(3-y));
           }
        ++ci;
        sm[ci].x=x+1;
        sm[ci].y=y+1;
        if(y==3)DFS(x+1,0,ci,w[0],w[1],w[2],w[3]);
        else DFS(x,y+1,ci,w[0],w[1],w[2],w[3]);
}
int main()
{
    int i,j,m,n;
    char t;
       // memset(s,0,sizeof(s));
        for(i=0;i<4;i++)
        {
          for(j=0;j<4;j++)
             {
             scanf("%c",&t);
             if(t=='-')s[i]+=(int)pow(2*1.0,(3.0-j*1.0));
             }
             getchar();
        }
        for(step=0;step<=16;step++)
       {
           if(DFS(0,0,0,s[0],s[1],s[2],s[3]))break;
          // else memset(sm,0,sizeof(sm));
       }
       //cout<<step<<endl;
       printf("%d\n",step);
       for(i=1;i<=step;i++)
       printf("%d %d\n",sm[i].x,sm[i].y);
          //cout<<sm[i].x<<' '<<sm[i].y<<endl;
    return 0;
}
