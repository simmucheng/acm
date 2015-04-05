#include<stdio.h>
int main ()
{
    int a,b,x,y,z,i,j=0;
    scanf("%d%d%d",&x,&y,&z);
    for(i=10;i<=100;i++)
    {
        if((i%3==x)&&(i%5==y)&&(i%7==z))
        {
            printf("%d\n",i);
            j=1;
            break;
        }

    }
    if(j==0)printf("No answer");
    return 0;
}
