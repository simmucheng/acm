#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int m,n,i,j,a,b,x,y,k;
    int s[100][100],c[100][100],d[100][100];
    memset(d,0,sizeof(d));
    cin>>a>>b;
    cin>>x>>y;
    for(i=1;i<=a;i++)
    for(j=1;j<=b;j++)
    cin>>s[i][j];
    for(i=1;i<=x;i++)
    for(j=1;j<=y;j++)
    cin>>c[i][j];
    for(i=1;i<=a;i++)
    for(j=1;j<=y;j++)
    for(k=1;k<=b;k++)
    d[i][j]+=s[i][k]*c[k][j];
    for(i=1;i<=a;i++)
    {
    for(j=1;j<=y;j++)
    cout<<d[i][j];
    cout<<endl;
    }
    return 0;
}
