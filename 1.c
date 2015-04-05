#include<stdio.h>
int main()
{
    int m,n,i,j,a[10000]={0};
    scanf("%d",&m);
    for(i=0;i<m;i++)
    scanf("%d",&a[i]);
    scanf("%d",&n);
    j=n%m;
    if(j!=0)
        printf("%d",a[0]);
    for(i=1;i<=m-1;i++)
    if(i==j)continue;
    printf(" %d",a[i]);
    printf("\n");
    return 0;
}
