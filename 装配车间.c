#include<stdio.h>
int main ()
{
    int s[2][10],t[2][10],l[2][10];
    int f[2][10];
    int i,j,m,n,a,b,p,q;
    for(j=0;j<2;j++)
    {
       for(i=1;i<7;i++)
          scanf("%d",&s[j][i]);
    }
    for(i=0;i<7;i++)
    scanf("%d",&t[0][i]);
    for(i=0;i<7;i++)
    scanf("%d",&t[1][i]);
    f[0][1]=t[1][0]+s[0][1];
    f[1][1]=t[0][0]+s[1][1];
    for(i=2;i<7;i++)
    {
        if((f[1][i-1]+t[1][i-1]+s[0][i])>(f[0][i-1]+s[0][i]))
        {f[0][i]=f[0][i-1]+s[0][i];l[0][i]=i;}
        else
        {f[0][i]=f[1][i-1]+t[1][i-1]+s[0][i];l[0][i]=10+i;}
        if((f[1][i-1]+s[1][i])<(f[0][i-1]+t[0][i-1]+s[1][i]))
        {f[1][i]=f[1][i-1]+s[1][i];l[1][i]=10+i;}
        else
        {f[1][i]=f[0][i-1]+t[0][i-1]+s[1][i];l[1][i]=i;}
        //printf("%d %d\n",f[0][i],f[1][i]);
        //printf("%d",s[1][1]);
    }
    if(f[0][6]+t[0][6]<f[1][6]+t[1][6])
    {p=f[0][6]+t[0][6];q=0;}
    else {p=f[1][6]+t[1][6];q=1;}
    printf("%d\n",p);
    for(i=6;i>=1;i--)
    {
    printf("The way is:%d %d\n",q+1,i);
    q=l[q][i]/10;
    }
    //printf("%d",l[0][0]);
    return 0;
}
