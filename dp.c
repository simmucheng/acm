#include<stdio.h>
#include<math.h>
int main()
{
    int m,n,i,j,a,k,s[1002][26],p[1002][26];
    int t,l,c;
    scanf("%d",&m);
    while(m--)
    {
        memset(s,0,sizeof(s));
        a=1000000100;
        scanf("%d%d%d",&c,&t,&l);
        for(i=1;i<=l;i++)
        p[0][i]=1000000100;
        for(i=0;i<c;i++)
        for(j=0;j<t;j++)
           {
               scanf("%d%d",&m,&n);
               s[i][m]=n;
               if(i==0)p[0][m]=n+m;
           }
            a=1000000100;
            for(i=1;i<c;i++)
            {
                for(j=0;j<l;j++)
                {
                    p[i][j]=1000000100;
                    if(s[i][j]==0){p[i][j]=1000000110;continue;}
                for(k=l;k>0;k--)
                {
                    if(p[i-1][k]==1000000110)continue;
                    m=p[i-1][k]+s[i][j]+abs(k-j);
                    p[i][j]=p[i][j]<=m?p[i][j]:m;
                }
                printf("%d\n",p[i][j]);
                }
            }
            for(j=0;j<l;j++)
            a=a<=p[c-1][j]+(l-j)?a:p[c-1][j]+(l-j);
        printf("%d\n",a);
    }
    return 0;
}
