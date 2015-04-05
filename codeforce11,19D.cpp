#include<iostream>
using namespace std;
int main()
{
    int i,j,m,n;
    int s[110][110];
    while(cin>>m)
    {
        int a=0;
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            cin>>s[i][j];
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==j)continue;
                a|=s[i][j];
            }
            cout<<a<<' ';
            a=0;
        }
        cout<<endl;
    }
    return 0;
}
