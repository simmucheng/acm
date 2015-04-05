#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long f[20];
long long dd[20];
long long s[20][20];
long long mo;
void init(long long nn)
{
    for(int ii=nn-1;ii>=1;ii--)
    s[ii][ii+1]=1;
    for(int ii=1;ii<=nn;ii++)
    s[nn][ii]=dd[ii];
}
long long ans[20][20];
void xx(long long w[20][20],long long e[20][20],long long nn)
{
    memset(ans,0,sizeof(ans));
    for(int ii=1;ii<=nn;ii++)
    {
        for(int jj=1;jj<=nn;jj++)
        {
            for(int kk=1;kk<=nn;kk++)
                {
                    ans[ii][jj]+=((w[ii][kk]%mo)*(e[kk][jj]%mo))%mo;
                    ans[ii][jj]%=mo;
                }
        }
    }
}
long long mians[20][20];
void getans(long long num,long long nn,long long e[20][20])
{
    memset(mians,0,sizeof(mians));
    for(int ii=1;ii<=nn;ii++)
    mians[ii][ii]=1;
    num-=nn;
    while(num)
    {
     if(num&1)
     {
        xx(mians,e,nn);
        for(int ii=1;ii<=nn;ii++)
        {
            for(int jj=1;jj<=nn;jj++)
           {
            mians[ii][jj]=ans[ii][jj];
           // cout<<ans[ii][jj]<<' ';
           }
        //  cout<<endl;
        }
      //  cout<<endl;
     }
     num>>=1;
     xx(e,e,nn);
    // cout<<"eeeee"<<endl;
      for(int ii=1;ii<=nn;ii++)
      {
         for(int jj=1;jj<=nn;jj++)
         {
             e[ii][jj]=ans[ii][jj];
            // cout<<e[ii][jj]<<' ';
         }
        // cout<<endl;
      }
     // cout<<endl;
    }
    return ;
}
long long next;
void get_la(long long nn)
{
        for(int jj=1;jj<=nn;jj++)
        {
            next+=(mians[nn][jj]*f[jj])%mo;
            next%=mo;
        }
}
int main()
{
    int i,j;
    long long n,d;
    while(scanf("%lld%lld%lld",&d,&n,&mo),d||n||mo)
    {
        next=0;
        memset(s,0,sizeof(s));
        for(i=d;i>=1;i--)
            scanf("%lld",&dd[i]);
        for(i=1;i<=d;i++)
            scanf("%lld",&f[i]);
        init(d);
        getans(n,d,s);
        get_la(d);
        printf("%lld\n",next);
    }
    return 0;
}
