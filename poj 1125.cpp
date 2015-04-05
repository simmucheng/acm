#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 0xfffffff
using namespace std;
int num;
int pp,mark;
int s[110][110];
int path[110];
void init()
{
    int l,k;
    for(l=1;l<=101;l++)
   {
     path[l]=0;
     for(k=1;k<=101;k++)
     s[l][k]=INF;
   }
}
void floyd()
{
    int i,j,k;
    for(k=1;k<=num;k++)
    for(i=1;i<=num;i++)
    {
      for(j=1;j<=num;j++)
       s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
    }
    return ;
}
bool findmax()
{
    int i,j,k;
    for(i=1;i<=num;i++)
    {
        for(j=1;j<=num;j++)
        path[i]=max(path[i],s[i][j]);

    }
    return true;
}
void findmin()
{
    pp=INF;
    for(int i=1;i<=num;i++)
    {
        if(pp>path[i])
        {pp=path[i];mark=i;}
    }
    return ;
}
int main()
{
    int i,j,m,n;
    while(cin>>num,num)
    {
        init();
        for(i=1;i<=num;i++)
        {
            s[i][i]=0;
            int y;
            cin>>y;
            for(j=1;j<=y;j++)
            {
            int x;
            cin>>x;
            cin>>s[i][x];
            }
        }
        floyd();
        findmax();
        findmin();
        cout<<mark<<' '<<pp<<endl;
       // else cout<<"disjoint"<<endl;
    }
    return 0;
}
