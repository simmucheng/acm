#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<int>q[210];
int main()
{
    int i,j,m,n;
    int s[210];
    while(scanf("%d%d",&m,&n),n||m)
    {
        int x1,x2;
        for(i=0;i<m;i++)
        scanf("%d%d",&x1,&x2);
        {
         q[x1].push_back(i);
         s[i]=x2;
        }
    }
}
