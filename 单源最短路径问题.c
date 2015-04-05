#include<stdio.h>
int main()
{
    int s[5][5];
    int w[5]={0},i,j,m,n,a,b,v[5]={0,1,2,3,4},con[5];
    int p,q,k;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        s[i][j]=10000;
    }
   /*for(i=0;i<7;i++)
    {
        scanf("%d%d%d",a,b,p);
        s[a][b]=p;
    }*/
    s[0][1]=10;
    s[1][2]=50;
    s[2][3]=20;
    s[3][4]=60;
    s[4][0]=100;
    s[0][3]=30;
    s[2][4]=10;
    //printf("%d\n",s[a][b]);
    for(p=0;p<5;p++)
    {
        for(i=0;i<5;i++)
    {
        if(m>s[0][i]){n=i;}
    }
    w[k++]=i;
    v[i]=0;
    for(q=1;q<5;q++)
    {
        for(j=1;j<5;j++)
        {
          if(w[j]>0)
        s[0][q]=s[0][q]<(s[0][w[j]]+s[w[j]][q])?s[0][q]:(s[0][w[j]]+s[w[j]][q]);
    }
    }
    }
    for(i=0;i<5;i++)
    printf("%d ",s[0][i]);
    return 0;
}
