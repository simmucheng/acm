#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<cstring>

using namespace std;
//ofstream pp("1.txt");
int top=1;
int prime[300];
void getprime()
{
    prime[1]=2;
    for(int ii=3;ii<=500;ii++)
    {
        int mark=0;
        for(int jj=2;jj<=sqrt(ii)+1;jj++)
        {
            if(ii%jj==0){mark=1;break;}
        }
        if(mark==0)
        prime[++top]=ii;
    }
    return ;
}
int s[120][300];
int ma[300][120];
int guess(int xx[300][120],int nn,int rr)
{
    int ii=1;
    int jj=1;
    while(ii<=nn&&jj<=rr)
    {
        int mm=ii;
        for(int kk=ii+1;kk<=nn;kk++)
        {
            if(xx[kk][jj]){mm=kk;break;}
        }
        if(mm!=ii||xx[ii][jj])
        {
            for(int kk=1;kk<=rr;kk++)
            swap(xx[ii][kk],xx[mm][kk]);
            for(int kk=ii+1;kk<=nn;kk++)
            {
                if(xx[kk][jj]==1)
                for(int dd=1;dd<=rr;dd++)
                    xx[kk][dd]^=xx[ii][dd];
            }
            ii++;
        }
        jj++;
    }
    return ii;
}
long long poww(int nn)
{
    long long sum=1;
    for(int ii=1;ii<=nn;ii++)
        sum*=2;
    return sum;
}
int main()
{
    getprime();
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        memset(s,0,sizeof(s));
        int sta=0;
        scanf("%d",&m);
        int r=0;
        int num=m;
        int getmax=-1;
        while(m--)
        {
           long long t;
           scanf("%lld",&t);
           int aa=1;
           if(t==1)continue;
           r++;
           while(t>1)
           {
               getmax=max(getmax,aa);
               while(t%prime[aa]==0)
               {
                   t/=prime[aa];
                   s[r][aa]++;
               }
               aa++;
           }
        }
        int ee;
        for(i=1;i<=getmax;i++)
        {
            for(j=1;j<=r;j++)
            {
                ma[i][j]=s[j][i]%2;
            }
        }
        int tt=guess(ma,getmax,r)-1;
        long long ans=poww(num-tt);
        printf("%lld\n",ans-1);
    }
    return 0;
}
