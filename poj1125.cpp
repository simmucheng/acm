#include<iostream>
#include<algorithm>
using namespace std;
int s[510][510];
void init()
{
    int i,j;
    for(i=1;i<=500;i++)
    {
        for(j=1;j<=500;j++)
        s[i][j]=100000;
    }
}
int main()
{
    int i,j,m,n;
    int mark;
    while(cin>>m,m)
    {
        init();
        for(i=1;i<=m;i++)
        {
            mark=0;
            cin>>n;
            int w;
            for(j=0;j<n;j++)
            {
                cin>>w;
                cin>>s[i][w];
            }
        }
        //cout<<"nivre"<<endl;
        for(int k=1;k<=m;k++)
        {
            for(i=1;i<=m;i++)
            {
                s[i][i]=0;
                for(j=1;j<=m;j++)
                s[i][j]=s[i][j]<s[i][k]+s[k][j]?s[i][j]:s[i][k]+s[k][j];
            }
        }
       /* for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
            cout<<s[i][j]<<' ';
            cout<<endl;
        }*/
        int mi=5000;
        int r;
        for(i=1;i<=m;i++)
        {
            sort(s[i]+1,s[i]+1+m);
            if(s[i][m]>=10000)
            continue;
            else
            {
                if(s[i][m]<mi)
                {
                    r=i;
                    mi=s[i][m];
                }
            }
        }
        if(mi>=10000)cout<<"disjoint"<<endl;
        else cout<<r<<' '<<mi<<endl;
    }
    return 0;
}
