#include<stdio.h>
int main ()
{
    int a,c,m,i,j;
    char b;
    char s[19];
    c=0;
    while(1)
    {
        scanf("%c",&b);
        a=b-'A';
        if(a==0)break;
        c++;
        printf("case %d:",c);
        putchar('\n');
        for(i=1; i<=a; i++)
        {
            for(j=1; j<=19; j++)
            {
                if(j<i)
                {
                    putchar(' ');
                }
                else if(j>=i&&j<=a)
                {
                    s[j]=65+j;
                    printf("%c",s[j]);
                }
                else if(j>a&&j<=2*a-1)
                {
                    for(m=1; m<=a-1; m++)
                    {
                        s[j]=a+65-m;
                    }
                    printf("%c",s[j]);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}
