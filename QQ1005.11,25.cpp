#include<iostream>
#include<map>
#include<cstring>
#include<cstdio>
using namespace std;
int s[100010];
int main()
{
    ios::sync_with_stdio(0);
    int i,j,m,n;
    int e;
    memset(s,-1,sizeof(s));
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            int t;
            scanf("%d%d",&e,&t);
            int y;
            for(j=0;j<t;j++)
            {

                scanf("%d",&y);
                s[y]=e;
            }
        }
        int r;
        scanf("%d",&r);
        int a,b,f,h;
        for(i=0;i<r;i++)
        {
            scanf("%d%d",&a,&b);
            f=a;
            h=b;
            while(1)
            {
                if(s[f]!=-1)
                f=s[f];
                else break;
            }
            while(1)
            {
                if(s[h]!=-1)
                h=s[h];
                else break;
            }
            if(f==h)cout<<"YES"<<endl;//printf("YSE\n");
            else cout<<"NO"<<endl;//printf("NO\n");
        }
        for(i=0;i<m;i++)
        s[i]=-1;
        //cout<<endl;
        printf("\n");
    }
    return 0;
}
