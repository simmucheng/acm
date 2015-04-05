#include<stdio.h>
#define N 100000000
#include<math.h>

int main()
{
    int i,c,n,f;

    while((scanf("%d",&c))==1){
    f=(int)sqrt(c*1.0);
    for(i=2;i<=f;i++){

    n=0;
    if(c%i==0){
    while(c%i==0){
    c=c/i;
    n++;
    }
    printf("%d",i);
    if(c==1){
    if(n>1)printf("^%d",n);
    }
    else {
    if(n==1)printf("*");
    else printf("^%d*",n);}
    }
    }
    if(c>f)  printf("%d",c);
    printf("\n");
    }
    return 0;
}
