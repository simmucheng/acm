#include<iostream>
#include<cstdio>
using namespace std;
int s[100100];
int m;
void init()
{
    int p;
    for(p=0;p<m;p++)
    s[p]=0;
}
int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        init();
        int u=0;
        for(j=0;j<m;j++)
                scanf("%d",&s[j]);
        for(j=0;j<m;j++)
        {
            if(s[j]>=0){u=1;break;}
        }
        int sum=0;
        int end=1,start=1;
        int e=s[0];
        if(u==1){
        for(j=0;j<m;j++)
        {
            if(s[j]>=0)
            {
                for(k=j;k<m;k++)
                {
                    sum+=s[k];
                    if(e<sum)
                    {
                        e=sum;
                        end=k+1;
                        start=j+1;
                    }
                    if(sum<0){sum=0;break;}
                }
                j=k;
            }
        }
        }
        else
        {
            for(j=0;j<m;j++)
            {
                if(e<s[j])
                {
                    e=s[j];
                    start=j+1;
                    end=j+1;
                }
            }
        }
        printf("Case %d:\n%d %d %d\n",i+1,e,start,end);
        if(i<n-1)
        cout<<endl;
    }
    return 0;
}
