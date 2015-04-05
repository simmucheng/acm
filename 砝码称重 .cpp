#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int s[6],p[6][1000];
    int i,j,k,m,n,a;
    int q[]={1,2,3,5,10,20};
    int c=0;
    memset(p,0,sizeof(p));
        for(i=0;i<6;i++)
        {
         scanf("%d",&s[i]);
         c+=s[i]*q[i];
        }
       //for(i=0;i<=s[i];i++)
       p[0][1]=1;
       p[1][2]=1;
        for(i=1;i<6;i++)
        {
            for(j=s[i];j<=c;j++)
            {
                int sum=0;
                for(k=0;k<=s[i];k++)
                //{if(j-k*q[i]>=0)
                sum=sum+p[i-1][j-k*q[i]];
                //}
                p[i][j]=sum;
                cout<<p[i][j]<<endl;
            }
        }
       // cout<<p[5][c]<<endl;
    return 0;
}
