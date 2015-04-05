#include<stdio.h>
#include<string.h>
int main()
{
    int m,n,i,k,j,x;
    char str[22][210];
    scanf("%d ",&m);
    for(n=1;n<=m;n++)
    {
        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%s",str[i]);
        }
        for(i=1;i<k;i++)
        {
            for(j=0;j<strlen(str[0]);j++)
            {
                if(str[0][j]!=str[i][j]) str[0][j]='\0';
            }
        }
        printf("Case %d: %s\n",n,str[0]);
    }
    return 0;
}
