#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int a,b,i,j,m,n,tem;
    int s[6000];
    int p[6000];
    b=0;
    while(scanf("%d",&tem)&&tem!=-1)
    {
        b++;
        i=1;
        memset(s,0,sizeof(s));
        memset(p,0,sizeof(p));
        while(1)
        {
        scanf("%d",&s[i++]);
        if(s[i-1]==-1)break;
        }
        s[0]=tem;
        m=i-1;
        int q=0;
        p[0]=1;

        for(i=1;i<m;i++)
        {
            int ma=0;
            for(j=0;j<i;j++)
            {
                if(s[i]<=s[j])
                    ma=max(ma,p[j]);
            }
           p[i]=ma+1;
           q=max(q,p[i]);
        }
        if(m==1)q=1;
        printf("Test #%d:\n",b);
        cout<<"  maximum possible interceptions: ";
        cout<<q<<endl<<endl;
    }
    return 0;
}
