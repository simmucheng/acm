#include<stdio.h>
int main()
{
    int a,m,n,i,j,t,p,q,b[110],e[110];
    while(scanf("%d",&n)==1){
    if(n==0)break;
    m=0;
    for(i=0;i<n;i++)
        scanf("%d%d",&b[i],&e[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-i-1;j++)
            {

                if(e[j]>e[j+1]){
                    t=e[j];
                    e[j]=e[j+1];
                    e[j+1]=t;
                    p=b[j];
                    b[j]=b[j+1];
                    b[j+1]=p;
                    }
            }
        }
        for(i=0;i<n;i++)
        q=e[0];
        for(i=0;i<n;i++)
        {
            if(q<=b[i+1]){m++;q=e[i+1];}
        }
        printf("%d\n",m);
    }
    return 0;
}
