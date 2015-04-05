#include<stdio.h>
int main ()
{
    int i,j,t,n,m,s[100];
    char a;
    //scanf("%d\n",&m);
   // for(j=0;j<m;j++){
    scanf("%d\n",&n);
    //a=getchar();
    for(i=0;i<n;i++){
    scanf("%d",&s[i]);
    }
   // while(1){
    //n=0;
    //if(a=='A'){
   // while(1)
    for(i=0;i<n;i++){
        n=0;
    if(s[i]<s[i-1]){
        n++;
    //n++;
    t=s[i];
    s[i]=s[i-1];
    s[i-1]=t;
    }
    if(n==0)break;
    }
    for(i=0;i<n;i++){
    printf("%d",s[i]);
    }
    //if(n==0)break;
    //}
    /*if(a=='D'){
    for(i=0;i<n;i++){
    if(s[i]>s[i-1]){
    n++;
    t=s[i-1];
    s[i-1]=s[i];
    s[i]=t;
    }
    if(n==0)break;
    }
    }
    for(i=0;i<n;i++){
    printf("%d",s[i]);
    }
    }
    }*/
      return 0;
}
