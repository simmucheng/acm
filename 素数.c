#include<stdio.h>
#include<math.h>
int main ()
{
    unsigned int a,i,n;
    while((scanf("%u",&a))==1){
        if(a==0) break;
        else if(a==1)printf("No\n");
        else if(a==2)printf("Yes\n");
        else{
            n=0;
            for(i=2;i<=(int)sqrt(a*1.0);i++){
                if(a%i==0){
                    printf("No\n");
                    n=1;
                    break;
                }
            }
            if(n==0) printf("Yes\n");
        }
    }
    return 0;
}
