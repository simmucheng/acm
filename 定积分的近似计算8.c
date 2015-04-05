#include<stdio.h>
#include<math.h>
int main(){
    int i;
    double N,j=0,y=0,a[10001],b[10001];
    scanf("%lf",&N);
    for(i=0;i<=N;i++){
        a[i]=1+j/N;
        b[i]=1/a[i];
        j++;
    }
    for(i=0;i<N;i++)
        y=y+1/N*b[i]-(1.0/4.0)*3.1415926*(b[i]-b[i+1]+1/N)/2*(b[i]-b[i+1]+1/N)/2;
        printf("%.10lf\n",log(2));
        printf("%.10lf\n",y);
        printf("%.10lf\n",log(2)-y);
        return 0;
}


