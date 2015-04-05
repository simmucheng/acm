#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int i,j,m,n;
    int s[6][6];
    int x,y;
    while(cin>>s[1][1])
    {
        if(s[1][1]==1){x=y=1;}
        for(i=1;i<=5;i++)
        {
            for(j=1;j<6;j++)
            {
                if(i==1&&j==1)continue;
                scanf("%d",&s[i][j]);
                if(s[i][j]==1){x=i;y=j;}
            }
        }
        cout<<abs(3-x)+abs(3-y)<<endl;
    }
    return 0;
}
