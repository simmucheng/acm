#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int l;
int sa[260][260];
const double eps = 1e-8;
struct node
{
    int x;
    int y;
}s[26];
bool mar[1000];
struct node1
{
    double a;
    double b;
    double c;
}w[10000];
void length(node t1,node t2,node t3)
{
    w[l].a=((double)((t1.x-t2.x)*(t1.x-t2.x)+(t1.y-t2.y)*(t1.y-t2.y)));
    w[l].b=((double)((t3.x-t2.x)*(t3.x-t2.x)+(t3.y-t2.y)*(t3.y-t2.y)));
    w[l].c=((double)((t1.x-t3.x)*(t1.x-t3.x)+(t1.y-t3.y)*(t1.y-t3.y)));
   // cout<<w[l].c<<endl;
    if(w[l].a>w[l].b)swap(w[l].a,w[l].b);
    if(w[l].b>w[l].c)swap(w[l].b,w[l].c);
    if(w[l].a>w[l].b)swap(w[l].a,w[l].b);
    l++;
}
bool com(node1 u1,node1 u2)
{
    if((u1.a*u2.b-u1.b*u2.a==0)&&(u1.a*u2.c-u1.c*u2.a==0)&&(u1.b*u2.c-u1.c*u2.b==0))
    return 1;
    else return 0;
}
int main()
{
    int i,j,m,n,k;
    while(scanf("%d",&m),m)
    {
      memset(s,0,sizeof(s));
      memset(sa,0,sizeof(sa));
      memset(w,0,sizeof(w));
      memset(mar,0,sizeof(mar));
      l=0;
      n=0;
      int w1,w2;
      for(i=0;i<m;i++)
      {
          scanf("%d%d",&w1,&w2);
          if(sa[w1+100][w2+100]>0)continue;
          else {
            sa[w1+100][w2+100]=1;
            s[n].x=w1;
            s[n].y=w2;
            n++;
               }
      }
      for(i=0;i<n;i++)
      {
          for(j=i+1;j<n;j++)
          {
              for(k=j+1;k<n;k++)
              {
                  if((s[j].y-s[i].y)*(s[k].x-s[j].x)==(s[k].y-s[j].y)*(s[j].x-s[i].x))continue;
                  length(s[i],s[j],s[k]);
              }
          }
      }
      int ans;
      int yu=0;
      for(i=0;i<l;i++)
      {
          if(mar[i]==0)
        {
          ans=1;
          mar[i]=1;
          for(j=i+1;j<l;j++)
          {
              if(mar[j]==1)continue;
              if(com(w[i],w[j])==1)
              {
                  ans++;
                  mar[j]=1;
              }
          }
          yu=yu>ans?yu:ans;
        }
      }
      printf("%d\n",yu);
    }
    return 0;
}
