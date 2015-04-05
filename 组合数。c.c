#include<stdio.h>
int main ()
{
    double  a,b,i,s[10000];
    int j;
    while((scanf("%lf",&a))){
          if(a<0)break;
          printf("2^%d=",(int)a);
        /* if(a=0){
          printf("1");}*/
          if(a>0) {
        printf("1+%d",(int)a);
    b=a;
    for(j=2;j<=a;j++){
    s[j]=a*(b-j+1)/j;
    a=s[j];
    printf("+%d",(int)s[j]);
    }
    putchar('\n');
    }

    else {
    printf("1");
    putchar('\n');}

    }
    return 0;
}


