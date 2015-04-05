#include<stdio.h>
#include<string.h>
long s[2010];
long w[2010][1000];
long cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
int main()
{
    long i,j,x,y;
    int n,m;
    long t1,t2,t3;
    while(scanf("%d%d",&m,&n)==2)
    {
        for(i=1;i<=m;i++)
            scanf("%ld",&s[i]);
        qsort(s+1,m,sizeof(s[0]),cmp);
        memset(w,0,sizeof(w));
        w[2][1]=(s[1]-s[2])*(s[1]-s[2]);
        for(i=3;i<=n;i++)
        {
            t1=i/2;
            t2=(s[i]-s[i-1])*(s[i]-s[i-1]);
            for(j=1;j<=t1;j++)
            {
                if(j<=n)
                {
                if(i>j*2)
                    w[i][j]=w[i-1][j]<(w[i-2][j-1]+t3)?w[i-1][j]:(w[i-2][j-1]+t2);
                else
                    w[i][j]=w[i-2][j-1]+(s[i-1]-s[i])*(s[i-1]-s[i]);
                }
            else break;
            }
        }
        printf("%ld\n",w[m][n]);
    }
    return 0;
}
