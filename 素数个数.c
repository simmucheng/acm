#include<stdio.h>
#define N 1000001
s[N]={0};
a[N]={0};
int main()
{
    int i,j,k,h,n,m,t;
    int x,y;
    for(i=2;i<=N;i++)
    s[i]=1;

    for(i=2;i<=N;i++){
    if(s[i]!=0){
        for(j=i+i;j<=N;j+=i){
        s[j]=0;
                }
        }
    }
     a[1]=0;
    for(i=2;i<N;i++){
        a[i]=a[i-1]+s[i];
        }
    scanf("%d\n",&h);
     for(k=1;k<=h;k++){
        scanf("%d %d",&x,&y);
        if(x>y){
        t=y;
        y=x;
        x=t;
        }
        printf("%d\n",a[y]-a[x-1]);}
        return 0;
}



