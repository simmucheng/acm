#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct nodee
{
    int mark;
    int nam;
}s[110][110];
struct node
{
    int x;
    int y;
    char t;
}w[110];
char dirction(char dd,int ee)
{
    int tt;
    if(dd=='E')tt=0;
    else if(dd=='N')tt=1;
    else if(dd=='W')tt=2;
    else tt=3;
    tt+=ee;
    tt=((tt%4)+4)%4;
    if(tt==0)return 'E';
    else if(tt==1)return 'N';
    else if(tt==2)return 'W';
    else if(tt==3)return 'S';
}
int main()
{
    int i,j,n,m;
    int num,order;
    int sia,sib;
    cin>>n;
    while(n--)
    {
        memset(s,0,sizeof(s));
        memset(w,0,sizeof(w));
        int maa=0;
        int mbb=0;
        int aa,bb,cc;
        cin>>sia>>sib>>num>>order;
        int l=1;
        while(num--)
        {
            int xx,yy;
            char tt;
            cin>>xx>>yy>>tt;
            s[xx][yy].mark=1;
            s[xx][yy].nam=l;
            w[l].x=xx;
            w[l].y=yy;
            w[l++].t=tt;
        }
        while(order--)
        {
            int na,rep;
            int mm;
            char dir;
            cin>>na>>dir>>rep;
            if(maa==1||mbb==1)continue;
            if(dir=='F')
            {
              cc=na;
              s[w[na].x][w[na].y].mark=0;
              if(w[na].t=='N')
              {
                  for(int l=1;l<=rep;l++)
                  {
                     if(w[na].y+l>sib){mbb=1;break;}
                     if(s[w[na].x][w[na].y+l].mark==1)
                     {aa=s[w[na].x][w[na].y+l].nam;maa=1;break;}
                  }
                  //if(maa==1||mbb==1)continue;
                  s[w[na].x][w[na].y+rep].mark=1;
                  s[w[na].x][w[na].y+rep].nam=na;
                  w[na].y+=rep;
              }
              else if(w[na].t=='S')
              {
                  for(int l=1;l<=rep;l++)
                  {
                     if(w[na].y-l<1){mbb=1;break;}
                     if(s[w[na].x][w[na].y-l].mark==1)
                     {aa=s[w[na].x][w[na].y-l].nam;maa=1;break;}
                  }
                  //if(maa==1||mbb==1)continue;
                  s[w[na].x][w[na].y-rep].mark=1;
                  s[w[na].x][w[na].y-rep].nam=na;
                  w[na].y-=rep;
              }
              else if(w[na].t=='W')
              {
                  for(int l=1;l<=rep;l++)
                  {
                      if(w[na].x-l<1){mbb=1;break;}
                      if(s[w[na].x-l][w[na].y].mark==1)
                      {aa=s[w[na].x-l][w[na].y].nam;maa=1;break;}
                  }
                  //if(maa==1||mbb==1)continue;
                  s[w[na].x-rep][w[na].y].mark=1;
                  s[w[na].x-rep][w[na].y].nam=na;
                  w[na].x-=rep;
              }
              else if(w[na].t=='E')
              {
                  for(int l=1;l<=rep;l++)
                  {
                      if(w[na].x+l>sia){mbb=1;break;}
                      if(s[w[na].x+l][w[na].y].mark==1)
                      {aa=s[w[na].x+l][w[na].y].nam;maa=1;break;}
                  }
                //  if(maa==1||mbb==1)continue;
                  s[w[na].x+rep][w[na].y].mark=1;
                  s[w[na].x+rep][w[na].y].nam=na;
                  w[na].x+=rep;
              }
              //cout<<w[na].x<<' '<<w[na].y<<' '<<w[na].t<<endl;
            }
            else if(dir=='L')
            {
                rep%=4;
                w[na].t=dirction(w[na].t,rep);
            }
            else if(dir=='R')
            {
                rep%=4;
                w[na].t=dirction(w[na].t,-rep);
            }
        }
        if(mbb==1)cout<<"Robot "<<cc<<" crashes into the wall"<<endl;
        else if(maa==1)cout<<"Robot "<<cc<<" crashes into robot "<<aa<<endl;
        else printf("OK\n");
    }
    return 0;
}

