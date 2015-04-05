#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
vector<int> w[101000];
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
    scanf("%d",&n);
    int num;
    int mark=0;
    int l=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<6;j++)
             scanf("%d",&s[i][j]);
    }
    for(i=0;i<n;i++)
    {
        num=0;
        //for(j=0;j<6;j++)num+=s[i][j];
        num=(s[i][0]+s[i][2]+s[i][4])^(s[i][1]+s[i][3]+s[i][5]);
        num%=90001;
        for(int k=0;k<w[num].size();k++)
        if(compare(i,w[num][k])){mark=1;break;}
        w[num].push_back(i);
    }
    if(mark==1)printf("Twin snowflakes found.\n");
    else printf("No two snowflakes are alike.\n");
    return 0;
}
