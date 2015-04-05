#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
int m,n,p;
int dp[510][510];
int q[510];
int s[510];
int w[510];
void init()
{
    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    dp[i][j]=0;
}
void pr(int a,int b,int ui)
{
    if(b<0)return;
    int con=0;
    int i;
    for(i=0;i<b;i++)
    {
        if(w[i]<w[b]&&dp[a][i]==ui)
        {
            con=1;
            q[p++]=w[i];
           // cout<<w[i]<<endl;
            pr(a-1,i,ui-1);
            break;
        }
        if(con==0){con=1;pr(a-1,i,ui);}
    }
}
int main()
{
    int n,m,i,j;
    while(scanf("%d",&m)!=EOF)
    {
        p=0;
//        memset(q,0,sizeof(q));
//        memset(s,0,sizeof(s));
//        memset(w,0,sizeof(w));
        for(i=0;i<m;i++)
        scanf("%d",&s[i]);
        scanf("%d",&n);
       // init();
        for(i=0;i<n;i++)
        scanf("%d",&w[i]);
        int mark=0;
        int er,l;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(s[i]==w[j])
                {
                    //int re=0;
                    for(int k=0;k<=i;k++)
                    {
                        if(s[i-k]<s[i]||i==0)
                        {
                            if(dp[i-k][j-1]+1>dp[i][j])
                            {
                               dp[i][j]=dp[i-k][j-1]+1;

                               }
                            }
                        }
                    }
                else
                {
                    dp[i][j]=dp[i][j-1];
                }
                if(mark<dp[i][j])
                {
                    mark=dp[i][j];
                    l=i;
                    er=j;
                }
            }
        }
       //cout<<l<<' '<<er<<endl;
       for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                //cout<<"vbweu"<<endl;
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<mark<<endl;
        q[p++]=s[l];
        pr(l-1,er,mark-1);
        //cout<<q[0]<<endl;
        for(i=mark-1;i>=0;i--)
        {
            if(i==mark-1)cout<<q[mark-1];
            else
            cout<<' '<<q[i];
        }
        cout<<endl;
    }
    return 0;
}
