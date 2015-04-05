#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int p[10];
int wei(int q)
{
    int t=0,n;
        while(q)
    {
        if(q/10)
        t++;
    }
    return t;
}
void mo(int w)
{
    memset(p,0,sizeof(p));
    while(w)
    {
        p[w%10]++;
        w/=10;
    }
}
int main()
{
    int i,j,m,n,l,k;
    int mark[10];
    int d=0;
    int h[10000];
    int s[10000][2];
    for(i=126;i<=1100000;i++)
    {
        mo(i);
        int x=0;
       cout<<i<<endl;
        for(j=1;j<=sqrt(i);j++){
            //cout<<j<<endl;
        if(i%j==0){//cout<<j<<' '<<i/j<<endl;
        s[x][0]=j;s[x][1]=i/j;x++;}
        }
        for(k=0;k<x;k++)
        {
            memset(mark,0,sizeof(mark));
            //cout<<s[k][0]<<"vdsv"<<s[k][1]<<"cfw"<<x-1<<"pppp";
            while(s[k][0])
            {
                mark[s[k][0]%10]++;
                s[k][0]/=10;
            }
             while(s[k][1])
            {
                mark[s[k][1]%10]++;
                s[k][1]/=10;
            }
            int r=0;
            for(int u=0;u<10;u++)
            //cout<<mark[u]<<' '<<p[u]<<endl;
            for(int e=0;e<10;e++)
            if(mark[e]-p[e]){r=1;break;}
            if(r==0){h[d++]=i;break;}
        }
    }
    for(j=0;j<1000;j++)
        cout<<h[j]<<',';
    return 0;
}
