#include<stdio.h>
#include<string.h>
int main()
{
    int w[100],sp[100],s[100],d[100];
    int i,j,m,n,a,b,max;
    while(scanf("%d",&n)==1)
    {

        scanf("%d%d",&m,&max);
        for(i=0;i<n;++)
            scanf("%d%d%d",&sp[i],&w[i],&d[i]);
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++)
        {
            if(d[i]==0){
            for(j=sp[i];j<=max;j++)
            {
                s[j]=s[j]>(s[j-sp[i]]+w[i])?s[j]:(s[j-sp[i]]+w[i]);
            }
        }
            if(d[i]==1)
            {
             for(j=max;j>=sp[i];j--)
            {
                s[j]=s[j]>(s[j-sp[i]]+w[i])?s[j]:(s[j-sp[i]]+w[i]);
            }
            }
            else (d[i]>1)
            {
                for
            }
        }
    }
}
