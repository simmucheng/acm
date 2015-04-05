#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<string>
#include<cstring>
#include<queue>
#define INF 0xfffffff
using namespace std;
struct node
{
    double ma;
    int number;
    int mark;
}path[32];
double w[32][32];
int mark[32],n;
map <string,int> qq;
queue <int> ee;
bool spfa()
{
    ee.push(1);
    path[1].number++;
    path[1].mark=1;
    while(!ee.empty())
    {
        int uu;
        uu=ee.front();
        ee.pop();
        path[uu].mark=0;
        for(int l=1;l<=n;l++)
        {
            if(path[l].ma<path[uu].ma*w[uu][l])
            {
                path[l].ma=path[uu].ma*w[uu][l];
                if(!path[l].mark)
                {
                    ee.push(l);
                    path[l].number++;
                    path[l].mark=1;
                }
                if(path[l].number>n-1)return false;
            }
        }
    }
    return true;
}
void init()
{
    for(int i=1;i<=31;i++)
    {
    path[i].ma=0;
    path[i].number=0;
    path[i].mark=0;
    for(int j=1;j<=31;j++)
    w[i][j]=0;
    }
    while(!ee.empty())ee.pop();
}
int main()
{
    int m,i,j;
    double t;
    string s,x,y;
    int rr=1;
    while(scanf("%d",&n),n)
    {
       // if(n==0)break;
        init();
        for(i=1;i<=n;i++)
        {
            cin>>s;
            qq[s]=i;
        }
        cin>>m;
        for(i=1;i<=m;i++)
        {
            cin>>x>>t>>y;
            w[qq[x]][qq[y]]=t;
        }
        path[1].ma=1;
        cout<<"Case "<<rr++<<": ";
        if(!spfa())cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
