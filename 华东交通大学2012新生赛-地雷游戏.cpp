#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int ab(int a,int b)
{
    if(a-b<0)return (b-a);
    else return a-b;
}
int main()
{
    int i,j,m,n,t,d;
    char s[52][52];
    cin>>t;
    int x,y;
    for(int l=0;l<t;l++)
    {
        memset(s,0,sizeof(s));
        cin>>n>>m>>d;
        for(i=0;i<n;i++)
            cin>>s[i];
        for(int k=0;k<m;k++)
        {
            cin>>x>>y;
            int num=0;
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(ab(x-1,i)+ab(y-1,j)<=d&&s[i][j]=='*')
                    num++;
                }
            }

            cout<<num<<endl;
        }
        if(l!=t-1)cout<<endl;
    }
    return 0;
}
