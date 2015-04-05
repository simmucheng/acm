#include<stdio.h>
int main()
{
    char str[201];
    int n,j,i;
    int m,h;
    scanf("%d\n",&m);
    for(h=0;h<m;h++){
    gets(str);
    n=strlen(str);
    if(n==1)printf("YES\n");
   else { for(i=0;i<n;i++){
    if((str[i]>='A')&&(str[i]<='Z')){
        str[i]=str[i]+32;
    }
    }
    for(i=0;i<(n/2);i++){
    j=0;
    if(str[i]!=str[n-i-1]){
    j=1;
    break;
    }
    else if(str[i]<'A'&&str[i]>'z')break;
    }
    if(j==0)printf("YES\n");
    if(j==1)printf("NO\n");
    }
    }
return 0;
}
