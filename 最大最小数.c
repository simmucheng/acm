#include<stdio.h>
int main ()
{
    int a,t,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a<b){
    t=a;
    a=b;
    b=t;
    }
    if(b<c){
    t=b;
    b=c;
    c=t;
    }
    if(a<b){
    t=a;
    a=b;
    b=t;
    }
    printf("%d %d",a,c);
    return 0;
}
