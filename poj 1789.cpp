#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#define INF 0xfffffff
using namespace std;
char s[2010][7];
int w[2010][2010];
int num,n;
struct node
{
    int ma;
    int mark;
}path[2010];
void change()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            for(int k=0;k<=6;k++)
            {
                if(s[i][k]!=s[j][k])
                {
                    w[i][j]++;
                    w[j][i]++;
                }
            }
        }
    }
    return ;
}
void prim()
{
    path[1].ma=0;
    int ee=1;
    int rr=0;
    while(ee)
    {
        ee=0;
        num+=rr;
        rr=INF;
        for(int l=1;l<=n;l++)
        {
            if(path[l].ma<rr&&!path[l].mark)
            {
                ee=l;
                rr=path[l].ma;
            }
        }
        path[ee].mark=1;
        for(int l=1;l<=n;l++)
        {
            if(path[l].ma>w[ee][l]&&!path[l].mark)
            path[l].ma=w[ee][l];
        }
    }
    return ;
}
void init()
{
    for(int l=1;l<=n;l++)
    {
        path[l].ma=INF;
        path[l].mark=0;
        for(int k=1;k<=n;k++)
        w[l][k]=0;
    }
    return ;
}
int main()
{
    int i,j,m;
    while(cin>>n,n)
    {
        num=0;
        init();
        for(i=1;i<=n;i++)
        scanf("%s",s[i]);
        change();
        prim();
        cout<<"The highest possible quality is 1/"<<num<<'.'<<endl;
    }
    return 0;
}
