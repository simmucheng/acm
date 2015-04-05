#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//int dir[][2]={-1,-1,-1,1,1,-1,1,1};]
int cot=0;
//int mark[10];
char s[10][10];
int n,k;
void dfs(int x,int y,int num,int mark)
{
    if(num==k){cot++;return ;}
    for(int r=x+1;r<n;r++)
    for(int l=0;l<n;l++)
        if(s[r][l]=='#'&&!(mark&(1<<l)))dfs(r,l,num+1,mark^(1<<l));
    return ;
}
int main()
{
    int i,j,m;
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)break;
        cot=0;
        for(i=0;i<n;i++)
        scanf("%s",s[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
            if(s[i][j]=='#'){dfs(i,j,1,1<<j);}
            }
        }
        cout<<cot<<endl;
    }
    return 0;
}
