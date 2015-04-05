#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int s[100010];
int mark[100010];
int main()
{
    int i,j,m,n,k;
    while(scanf("%d%d%d",&m,&n,&k)!=EOF)
    {
        memset(mark,0,sizeof(mark));
        for(i=1;i<=m;i++)
        scanf("%d",&s[i]);
        int mm=n;
        int tt=0;
        int ee=0;
        while(mm!=k)
        {
            if(!mark[mm]){mark[mm]=1;}
            else {ee=1;break;}
            tt++;
            mm=s[mm];
            //cout<<mm<<endl;
        }
        if(ee==1)printf("-1\n");
        else printf("%d\n",tt);
    }
    return 0;
}

