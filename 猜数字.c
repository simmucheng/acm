#include<stdio.h>
#include<string.h>
int main()
{
    char s[21][4],c[4];
    int i,j,a,b,n,m,k;
    while(scanf("%s",&c)==1){
        if(c[0]=='0')break;
    scanf("%d",&a);
    getchar();
    for(i=0;i<a;i++)
     scanf("%s",&s[i]);
    for(i=0;i<a;i++)
    {
        n=0;
        m=0;
        for(j=0;j<4;j++)
        {
             if(s[i][j]==c[j])n++;

             for(k=0;k<4;k++)
             {
                 if(s[i][k]==c[j])m++;
             }
        }
        if(i==a-1)printf("%dA%dB\n",n,m-n);
        else printf("%dA%dB ",n,m-n);
    }
    }
    return 0;
}
