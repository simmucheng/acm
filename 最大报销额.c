#include<stdio.h>
int main()
{
    int a,b,m,n,i,j,x,y,p[31],w[100000],con[31],t;
    char k;
    double price,p1,s[3];
    memset(s,0,sizeof(s));
    scanf("%lf%d",&price,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            scanf("%c",&k);
            getchar();
            scanf("%lf",&p1);
            if(k=='A')s[0][j]++;
            else if(k=='B')s[1][j]++;
            else if(k=='C')s[2][j]++;
            else continue;
            for(x=0;x<3;x++)
            {if(s[x]>600)continue;}
            p[j]=(int)(s[0][j]+s[1][j]+s[2][j])*100;
        }
    }
            t=0;
         for(i=0;i<m;i++)
         {
             if(con[i-1]+p[i]>price){con[i]==con[i-1];}
             else con[i]=con[i-1]+price;
         }
         printf("%d\n",con[m-1]);
    }

