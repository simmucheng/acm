#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int dp[120010];
int s[100];
int num;
void init()
{
    int f;
    for(f=0;f<=num;f++)
    dp[f]=0;
}
int main()
{
    int i,j,m,n,l;
    int p[6];
    int e=0;
    while(scanf("%d%d%d%d%d%d",&p[0],&p[1],&p[2],&p[3],&p[4],&p[5]),p[0]||p[1]||p[2]||p[3]||p[4]||p[5])
    {
        printf("Collection #%d:\n",++e);
        num=0;
        for(i=0;i<6;i++)
            num+=p[i]*(i+1);
        if(num%2!=0)printf("Can't be divided.\n\n");
        else
        {
            num/=2;
            init();
            memset(s,0,sizeof(s));
            int y=0;
            for(i=0;i<6;i++)
            {
                int k=0;
                if(p[i]==1)s[y++]=i+1;
                else if(p[i]>1)
               {
                 while(1)
                {
                    if((p[i]-pow(2,k)+1>0)&&(p[i]-pow(2,k+1)+1<=0))break;
                    ++k;
                }
                for(j=0;j<k;j++)
                {
                    s[y++]=pow(2,j)*(i+1);
                }
                s[y++]=(p[i]-pow(2,k)+1)*(i+1);
               }
            }
            dp[s[0]]=s[0];
            int mark=0;
             for(j=1;j<y;j++)
              {
                for(i=num;i>=s[j];i--)
                 {
                    dp[i]=max(dp[i-s[j]]+s[j],dp[i]);
                    if(i==num&&dp[i]==i){mark=1;break;}
                   //cout<<j<<' '<<i<<' '<<dp[i]<<endl;
                 }
                 if(mark==1)break;
              }
            if(mark==1)
                  printf("Can be divided.\n\n");
            else if(mark==0)printf("Can't be divided.\n\n");
        }
    }
    return 0;
}
