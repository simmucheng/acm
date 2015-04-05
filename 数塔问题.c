#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,m,n,a[100][100]={0};
    scanf("%d",&m);
    while(m--)
    {
        memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {for(j=0;j<=i;j++)
    scanf("%d",&a[i][j]);}
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            n=a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1];
            a[i][j]=a[i][j]+n;
        }
    }
    printf("%d\n",a[0][0]);
                           }
    return 0;
}
