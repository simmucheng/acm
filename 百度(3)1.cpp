#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
struct node
{
    int x;
    int y;
    int ma;
    int e[310];
    int nu;
}s[310];
int main()
{
    int i,j,m,n;
    int num;
    cin>>num;
    while(num--)
    {
        memset(s,0,sizeof(s));
        int a=0;
        int b=0;
        cin>>n>>m;
        for(i=0;i<n;i++)
        {
            cin>>s[i].x>>s[i].y>>s[i].ma;
            if(s[i].ma==0)a++;
            else b++;
        }
        for(i=0;i<n;i++)
        {
            int l=0;
            for(j=0;j<n;j++)
            {
                if(s[i].ma==s[j].ma)continue;
                s[i].e[++l]=(int)sqrt(pow(s[i].x-s[j].x,2)+pow(s[i].y-s[j].y,2));
               // cout<<s[i].e[l]<<endl;
            }
            s[i].nu=l;
           // cout<<l<<"aaaa"<<n<<endl;
        }
        //for(i=0;i<n;i++)
       // sort(s[i].e,s[i].e+s[i].nu,cmp);
        if(m<=a||m<=b)cout<<'1'<<endl;
        else
        {
            a=m-a;
            b=m-b;
            int nua=0;
            int nub=0;
                int mia=0xfffffff;
                for(i=0;i<m;i++)
                {
                    if(s[i].ma==0)
                    {
                        int y;
                        int g=0xfffffff;
                        for(int k=0;k<a;k++)
                        {
                            for(j=1;j<=s[i].nu;j++)
                             {
                                if(s[i].e[j]==-1)continue;
                                if(g>s[i].e[j])
                                {g=s[i].e[j];y=j;}
                             }
                           s[i].e[j]=-1;
                        }
                        mia=min(mia,g);
                    }
                }
                int mib=0xfffffff;
                for(i=0;i<m;i++)
                {
                    if(s[i].ma==1)
                    {
                        int y;
                        for(int k=0;k<b;k++)
                        {
                            int g=0xfffffff;
                            for(j=1;j<=s[i].nu;j++)
                             {
                                if(s[i].e[j]==-1)continue;
                                if(g>s[i].e[j])
                                {g=s[i].e[j];y=j;}
                             }
                           s[i].e[j]=-1;
                        }
                       // cout<<s[i].e[y]<<endl;
                        mib=min(mib,s[i].e[y]);
                       // cout<<mib<<endl;
                    }
            }
            int r=max(mia,mib);
            cout<<r<<endl;
        }
    }
    return 0;
}
