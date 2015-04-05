#include<stdio.h>
int main()
{
    int a,b,m,n,i,j;
    while(scanf("%d",&a)==1)
    {
        if(a==0)break;
        for(i=0;;i++){
            if(a==1)break;
            if(a%2==0)a/=2;
            else a=(a*3+1)/2;
                     }
        printf("%d\n",i);
    }
    return 0;
}
