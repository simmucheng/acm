#include<cstdio>
#include<iostream>
#include<stack>
#include<cstring>
#include<queue>
using namespace std;
const int N=20100;
struct hh
 {
     int u,v,next;
 }tp1[N*4],tp2[N*4];
stack<int>s;
int n,m,step,total,num1,num2,head1[N],head2[N],low[N],lp[N];
int f[N],col[N],cf[N],d[N];
int in[N];
int dd[110][110];
int mark[110];
void add1(int a,int b)
 {
     tp1[num1].u=a; tp1[num1].v=b; tp1[num1].next=head1[a];
     head1[a]=num1++;
 }
 void add2(int a,int b)
 {
     tp2[num2].u=a; tp2[num2].v=b; tp2[num2].next=head2[a];
     head2[a]=num2++;
 }
void  init()
 {
     int a,b;
     for(int i=0;i<N;i++)
      {
          head1[i]=head2[i]=-1;
          low[i]=lp[i]=f[i]=col[i]=cf[i]=d[i]=0;
          in[i]=0;
      }
      while(!s.empty()) s.pop();
      num1=num2=0; step=total=1;
      int ans;
      for(int ii=1;ii<=n;ii++)
        while(scanf("%d",&ans),ans)
        dd[ii][ans]=1;

       for(int ii=1;ii<=n;ii++)
       {
           for(int jj=ii+1;jj<=n;jj++)
           {
               if(dd[ii][jj]&&dd[jj][ii])
               {
                   add1(ii+1,(jj^1)+1);
                   add1(jj+1,(ii^1)+1);
               }
           }
       }
 }
   void tarjan(int u)
   {
       int v;
       s.push(u); in[u]=1;
       low[u]=lp[u]=step++;
       for(int i=head1[u];i!=-1;i=tp1[i].next)
        {
            v=tp1[i].v;
            if(!lp[v])
             {
                 tarjan(v); low[u]=min(low[u],low[v]);
             }
             else if(in[v])
             low[u]=min(low[u],lp[v]);
        }
        if(low[u]==lp[u])
         {
             int haha;
             while(1)
              {
                  haha=s.top(); s.pop(); in[haha]=0;
                  f[haha]=total;
                  if(haha==u) break;
              }
              total++;
         }
   }
   bool suodian()
   {
       int u,v;
       for(int i=1;i<=n;i++)
        {
            if(f[2*i-1]==f[2*i]) return false;
            cf[f[2*i-1]]=f[2*i];
            cf[f[2*i]]=f[2*i-1];
        }
        for(int i=0;i<num1;i++)
         {
             u=tp1[i].u; v=tp1[i].v;
             if(f[u]!=f[v])
              {
                  add2(f[v],f[u]); d[f[u]]++;
              }
         }
        return true;
   }
   void dfs(int u)
    {
        col[u]=-1;
        for(int i=head2[u];i!=-1;i=tp2[i].next)
         {
             if(!col[tp2[i].v]) dfs(tp2[i].v);
         }
    }
 void ranse()
  {
      int u,v;
      queue<int>q;
      for(int i=1;i<total;i++)
       {
           if(d[i]==0) q.push(i);
       }
       while(!q.empty())
        {
            u=q.front(); q.pop();
            if(0==col[u])
             {
                 col[u]=1; col[cf[u]]=-1;
                 dfs(cf[u]);
             }
            for(int i=head2[u];i!=-1;i=tp2[i].next)
             {
                 v=tp2[i].v;
                 if((--d[v]==0)&&(col[v]==0))
                 q.push(v);
             }
        }
     for(int i=1;i<=n;i++)
          if(col[f[i]]==1)mark[i]=1;
  }
int main()
 {
     while(scanf("%d",&n)!=EOF)
     {
         init();
         for(int i=1;i<=n;i++)
         if(!lp[i]) tarjan(i);
         if(suodian())
          ranse();
         else printf("NIE\n");
     }
     return 0;
 }
