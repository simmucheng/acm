#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> w[1001000];
//map<__int64,int> q;
int q[1001000];
int s[100010][6];
int compare(int x,int y)
{
    for(int ii=0;ii<6;ii++)
    {
        if(
           s[x][0]==s[y][ii%6]&&
           s[x][1]==s[y][(ii+1)%6]&&
           s[x][2]==s[y][(ii+2)%6]&&
           s[x][3]==s[y][(ii+3)%6]&&
           s[x][4]==s[y][(ii+4)%6]&&
           s[x][5]==s[y][(ii+5)%6]
           )
           return 1;
        if(
           s[x][0]==s[y][(ii+5)%6]&&
           s[x][1]==s[y][(ii+4)%6]&&
           s[x][2]==s[y][(ii+3)%6]&&
           s[x][3]==s[y][(ii+2)%6]&&
           s[x][4]==s[y][(ii+1)%6]&&
           s[x][5]==s[y][ii%6]
           )
           return 1;
    }
    return 0;
}
int main()
{
    int i,j,m,n;
    cin>>n;
    int num;
    int mark=0;
    for(i=0;i<n;i++)
    {
        int l=1;
        num=0;
        for(j=0;j<6;j++)
        {
            scanf("%d",&s[i][j]);
            num+=s[i][j];
            num%=999983;
            if(mark==0)
            {
               if(q[num])
               {
                for(int k=0;k<w[q[num]].size();k++)
                if(compare(i,w[q[num]][k]))mark=1;
                w[q[num]].push_back(i);
               }
            else {q[num]=l++;w[q[num]].push_back(i);}
            }
        }
    }
    if(mark==1)cout<<"Twin snowflakes found."<<endl;
    else cout<<"No two snowflakes are alike."<<endl;
    return 0;
}

