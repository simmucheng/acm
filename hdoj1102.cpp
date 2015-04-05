#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    int s[1100][1100];
    int mark[1100];
    while(cin>>n)
    {
        int num=0;
        memset(mark,0,sizeof(mark));
        int k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
            cin>>s[i][j];
            s[j][i]=s[i][j];
            }
        }
        cin>>m;
        for(=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            mark[a]=mark[b]=1;
            num+=c;
            //p[b][a]=p[a][b]=c;

        }
        for(i=0;i<n;i++)
        {
            int ma=0xfffffff;
            for(j=0;j<n;j++)
            {
                if(!mark[i]&&s[i][j]<ma)
                   {
                      ma=s[i][j];
                   }
                if(ma==0xfffffff)ma=0;
            }
             num+=ma;
        }
    }
    return 0;
}
