#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        for(i=1;i<=10;i++)
        {
            if(m%i==0)
                m/=i;
            else
            {
                if((m-1)%i==0)
                {
                    m--;
                    m/=i;
                }
                else break;
            }
            //cout<<"m = "<<m<<endl;
            if(m==1)break;
        }
        if(m==1)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
