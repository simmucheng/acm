#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//__int64 dp[40];
char w[40][110];
void add(int x,int y)
{
    //cout<<"bnrth"<<endl;
    int mark=0;
    for(int l=0;;l++)
    {
        if(w[y][l]=='0')break;
        int e=(w[x][l]-'0')+(w[y][l]-'0')+mark;
       // cout<<l<<' '<<x<<' '<<e<<endl;
        if(e>9){w[x][l]=e%10+'0';mark=1;}
        else {w[x][l]=e+'0';mark=0;}
       // cout<<w[x][l];
    }
    //cout<<endl;
}
int main()
{
    int i,j,m,n;
    while(cin>>n>>m,m||n)
    {
        memset(w,'0',sizeof(w));
       // memset(dp,0,sizeof(dp));
        //cout<<w[1][1];
       // dp[1]=1;
        w[1][0]='1';
        for(i=2;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(i-j<1)continue;
                add(i,i-j);
            }
            for(int e=0;e<10;e++)
            {
                if(w[i][e]=='0')break;
                else
                cout<<w[i][e];
            }
            cout<<endl;
        }
       /* for(int u=0;;u++)
        {
            if(w[n][u]=='0')break;
            printf("%c",w[n][u]);
        }*/
        cout<<endl;
    }
    return 0;
}


