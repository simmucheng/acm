#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int s[30][1300],p[30][1300],q[30][1300];
int main()
{
    int m,n,a,i,j,k;
    int t,l,c;
    cin>>m;
    while(m--)
    {
        cin>>c>>t>>l;
        for(i=0;i<c;i++)
        for(j=0;j<t;j++)
               cin>>q[i][j]>>s[i][j];
            for(i=0;i<c;i++)
            {
                for(j=0;j<t;j++)
            {
                if(i==0)p[0][j]=s[0][j]+q[0][j];
                else p[i][j]=0xfffffff;
            }
            }
            for(i=1;i<c;i++)
            {
                for(j=0;j<t;j++)
                {
                   for(k=0;k<t;k++)
                   p[i][j]=min(p[i][j],p[i-1][k]+abs(q[i][j]-q[i-1][k])+s[i][j]);
                }
            }
            a=0xfffffff;
            for(j=0;j<t;j++)
            a=min(a,p[c-1][j]+l-q[c-1][j]);
       cout<<a<<endl;
    }
}
