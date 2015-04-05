#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node1
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
    int i,j,n,n;
    int num,order;
    int sia,sib;
    cin>>n;
    while(n--)
    {
        cin>>sia>>sib>>num>>order;
        int l=1;
        while(num--)
        {
            int xx,yy;
            char tt;
            cin>>xx>>yy>>tt;
            s[xx][yy]=1;
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
            if(dir=='F')
            {
              s[w[na].x][w[na].y].mark=0;
              if(w[na].t=='N')
              {
                  if(w[na].y+rep>sib){cout<<"Robot "<<na<<"crashes into the wall"<<endl;break;}
                  if(s[w[na].x][w[na].y+rep].mark==1){cout<<"Robot "<<na<<" crashes into robot "<<s[w[na].x][w[na].y+rep].nam<<endl;reak;}
                  s[w[na].x][w[na].y+rep].mark=1;
                  s[w[na].x][w[na].y+rep].nam=na;
              }
              else if(w[na].t=='S')
              {
                  if(w[na].y-rep<1){cout<<"Robot "<<na<<"crashes into the wall"<<endl;break;}
                  if(s[w[na].x][w[na].y-rep].mark==1){cout<<"Robot "<<na<<" crashes into robot "<<s[w[na].x][w[na].y-rep].nam<<endl;break;}
                  s[w[na].x][w[na].y-rep].mark=1;
                  s[w[na].x][w[na].y-rep].nam=na;
              }
              else if(w[na].t=='W')
              {
                  if(w[na].x-rep<1){cout<<"Robot "<<na<<"crashes into the wall"<<endl;break;}
                  if(s[w[na].x-rep][w[na].y].mark==1){cout<<"Robot "<<na<<" crashes into robot "<<s[w[na].x-rep][w[na].y].nam<<endl;break;}
                  s[w[na].x-rep][w[na].y].mark=1;
                  s[w[na].x-rep][w[na].y].nam=na;
              }
              else if(w[na].t=='E')
              {
                  if(w[na].x+rep>sia){cout<<"Robot "<<na<<"crashes into the wall"<<endl;break;}
                  if(s[w[na].x+rep][w[na].y].mark==1){cout<<"Robot "<<na<<" crashes into robot "<<s[w[na].x+rep][w[na].y].nam<<endl;break;}
                  s[w[na].x+rep][w[na].y].mark=1;
                  s[w[na].x+rep][w[na].y].nam=na;
              }
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
            printf("OK\n");
        }
    }
    return 0;
}
