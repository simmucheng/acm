#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
__int64 mm=1000000007;
int ee[20];
int mark[20];
int m[20];
__int64 num;
int uu=3;
int judge()
{
    memset(mark,0,sizeof(mark));
    for(int l=1;l<=uu;l++)
    cout<<m[l]<<' ';
    for(int l=1;l<=uu;l++)
    {
        int y=(m[l]+l)%uu;
        if(!mark[y])mark[y]=1;
        else return 0;
    }
    return 1;
}
void ww(int t)
{
    if(t==uu){if(judge())num++;memset(ee,0,sizeof(ee));}
    for(int i=0;i<uu;i++)
    {
        if(!ee[i])ee[i]=1;
        else continue;
        m[t]=i;
        ww(t+1);
    }
    return ;
}
int main()
{
    ww(1);
    cout<<num<<endl;
    return 0;
}

