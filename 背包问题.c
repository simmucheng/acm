#include<stdio.h>
int main()
{
    int i,j,m,n,s;
    int p[500],q[500];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&s);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        scanf("%d",&p[i]);
        for(i=0;i<m;i++)
        q[i]=-100000;
        for(j=0;j<m;j++)
        {
            for(i=s;s>=0;i--)
            {
                q[i]=q[i-p[j]]+p[j];
            }
        }
    }
}
