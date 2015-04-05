#include<stdio.h>
int main()
{
    char s[100];
    int i,j,k;
    gets(s);
    int m=strlen(s);
    for(i=1;i<m;i++)
    {
        if(m%i==0)
        {
            k=1;
            for(j=i;j<m;j++)
            {
                if(s[j]!=s[j%i])
                {
                    k=0;
                    break;
                }
            }
            if(k==1)  {
                        printf("%d",m/i);
                        break;
                      }
        }
    }
    if(k==0)putchar('1');
    return 0;
}
