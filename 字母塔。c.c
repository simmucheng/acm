#include<stdio.h>
int main()
{
    int i,j,k,s,x;
    char a;
    for(k=1;;k++)
    {
        scanf("%c",&a);
        x=a;
        if(a=='#'||a<65||a>90)break;
        getchar();
        printf("case %d:\n",k);
        for(i=1;i<=a-64;i++)
        {   s='A';
            x=a;
            for(j=1;j<=i-1;j++)
            {
                printf(" ");
            }
            for(j=1;j<=a-64-i;j++)
            {
                printf("%c",s);
                s++;
            }
            for(j=1;j<=a-64-i+1;j++)
            {
                printf("%c",x-i+1);
                x--;
            }

            printf("\n");
        }

    }
    return 0;
}
