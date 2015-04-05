#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int mark[70][70][70];
struct node
{
    int a1;
    int b1;
    int c1;
}s[300000];
int a,b,c;
int dir[6][3]={0,0,1,0,0,-1,1,0,0,-1,0,0,0,1,0,0,-1,0};
void change(int aa,int bb,int cc,int nn)
{
    int a1,b1,c1;
    a1=nn/(aa*bb);
    b1=(nn%(aa*bb))/aa;
    c1=(nn%(aa*bb))%aa;
    mark[c1+1][b1+1][a1+1]=1;
    return ;
}
void bfs(int aa,int bb,int cc)
{
    int ee,ss;
    ee=0;
    ss=0;
    mark[aa][bb][cc]=-1;
    s[ss].a1=aa;
    s[ss].b1=bb;
    s[ss++].c1=cc;
    while(ss>=ee)
    {
       //cout<<ss<<' '<<ee<<endl;
       aa=s[ee].a1;
       bb=s[ee].b1;
       cc=s[ee++].c1;
       for(int ii=0;ii<=5;ii++)
      {
        int xx=dir[ii][0]+aa;
        int yy=dir[ii][1]+bb;
        int zz=dir[ii][2]+cc;
        if(xx<0||xx>(a+1)||yy<0||yy>(b+1)||zz<0||zz>(c+1))continue;
        if(!mark[xx][yy][zz])
        {
            mark[xx][yy][zz]=-1;
            s[ss].a1=xx;
            s[ss].b1=yy;
            s[ss++].c1=zz;
        }
      }
      //cout<<ee<<' '<<ss<<endl;
    }
    return ;
}
int main()
{
    int i,j,m,n;
    while(scanf("%d%d%d%d",&a,&b,&c,&n),a||b||c||n)
    {
        int sum=0;
        memset(mark,0,sizeof(mark));
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            change(a,b,c,m);
        }
        bfs(0,0,0);
        for(int ii=1;ii<=a;ii++)
        {
            for(int jj=1;jj<=b;jj++)
            {
                for(int kk=1;kk<=c;kk++)
                {
                    if(mark[ii][jj][kk]==1)
                    {
                        for(int ll=0;ll<=5;ll++)
                        {
                            int xx=dir[ll][0]+ii;
                            int yy=dir[ll][1]+jj;
                            int zz=dir[ll][2]+kk;
                            if(xx<0||xx>(a+1)||yy<0||yy>(b+1)||zz<0||zz>(c+1))continue;
                            if(mark[xx][yy][zz]==-1)
                            {
                                sum++;
                            }
                        }
                    }
                }
            }
        }
        printf("The number of faces needing shielding is %d.\n",sum);
    }
    return 0;
}
