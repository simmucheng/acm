#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    __int64 a,b,n;
    int i,k,m;
    while(scanf("%I64d%I64d%I64d",&a,&b,&n)!=EOF)
    {
        int mark=1;
        if(b>10&&n>=2)printf("-1");
        else if(b>10&&n==1)
        {
            for(i=0;i<10;i++)
            if((a*10+i)%b==0){a=a*10+i;mark=0;break;}
            if(mark==1)printf("-1");
            else printf("%I64d",a);
        }
        else if(b==10)
        {
            printf("%I64d",a);
            while(n--)
            printf("0");
        }
        else
        {
            for(i=0;i<10;i++)
            if((a*10+i)%b==0){a=a*10+i;mark=0;break;}
            if(mark==1){printf("-1");break;}
            else printf("%I64d",a);
            n--;
            while(n--)
            printf("%I64d",b);
        }
        printf("\n");
    }
    return 0;
}
