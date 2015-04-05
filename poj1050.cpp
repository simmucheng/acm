#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,r[110];
int ma()
{
    int l;
    int sum=0;
    int mi=-1*0xfffff;
    for(l=0;l<n;l++)
    {
        if(sum>=0)
       {
           sum+=r[l];
           if(sum>mi)
           mi=sum;
       }
        else sum=r[l];
    }
    if(sum<=0)
    {
        sort(r,r+n);
        mi=r[n-1];
    }
    return mi;
}
int main()
{
    int m,i,j;
    int s[110][110];
    int h[110];
    int e[110];
    int mx=-1*0xffffff;
    memset(e,0,sizeof(e));
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>s[i][j];
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
              memset(r,0,sizeof(r));
              for(int g=i;g<=j;g++)
              for(int k=0;k<n;k++)
              r[k]+=s[g][k];
              int t=ma();
              mx=t>mx?t:mx;
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}
