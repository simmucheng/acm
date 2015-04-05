#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    char t;
    int a[4][4];
    memset(a,0,sizeof(a));
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%c",&t);
            if(t=='+')
            {
                for(int l=0;l<4;l++)
                a[i][l]++;
                for(int l=0;l<4;l++)
                a[l][j]++;
                a[i][j]--;
            }

        }getchar();
    }
    int con=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            a[i][j]%=2;
            if(a[i][j])con++;
        }
    }
    cout<<con<<endl;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        if(a[i][j])cout<<i+1<<' '<<j+1<<endl;
    }
    return 0;
}
