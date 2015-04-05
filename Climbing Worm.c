#include<stdio.h>
int main()
{
    int a,b,c,i,j,m,n;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        if(a==0)break;
        for(i=1,j=1;;i++,j++)
        {
            m=b*i-c*(j-1);
            if(m>=a){j=j-1;break;}
            else m-=c;
        }
        printf("%d\n",i+j);
    }
    return 0;
}
