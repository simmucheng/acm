#include<stdio.h>
int main ()
{
    char a,b,m,i;
    int j,n=0;
    while(1){
    scanf("%c",&a);
    getchar();
    if(a=='#')break;
    n++;
    printf("case %d:\n",n);
    for(b=a;b>='A';b--){
        for(m=0;m<(int)(a-b);m++){
     putchar(' ');
        }
    for(i='A';i<=b;i++){
    putchar(i);
    }
    for(i=b-1;i>='A';i--){
    putchar(i);
    }
    putchar('\n');
    }
    }
    return 0;
}
