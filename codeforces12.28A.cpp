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
            for(i=0;i<10;i++)
            if((a*10+i)%b==0){a=a*10+i;mark=0;break;}
            if(mark==1){printf("-1");break;}
            else {
                  printf("%I64d",a);
                  n--;
                  while(n--){printf("0");}
                 }
        printf("\n");
    }
    return 0;
}
