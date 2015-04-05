#include<stdio.h>
int main()
{
int a,b,c,n,m,k,d,i;
scanf("%d\n",&d);

for(i=1;i<=d;i++){
    scanf("%d-%d-%d",&a,&b,&c);
if((a%4==0)&&(a%100!=0)){
    n=29;}
   else if(a%400==0){
    n=29;}
    else {
        n=28;
    }

if(b==1){
m=c;
}
else if(b==2){
m=31+c;}
else if(b==3){
m=31+n+c;}
else if(b==4){
m=31+n+31+c;}
else if(b==5){
m=31+n+31+30+c;}
else if(b==6){
m=31+n+31+30+31+c;}
else if(b==7){
m=31+n+31+30+31+30+c;}
else if(b==8){
m=31+n+31+30+31+30+31+c;}
else if(b==9){
m=31+n+31+30+31+30+31+31+c;}
else if(b==10){
m=31+n+31+30+31+30+31+31+30+c;}
else if(b==11){
m=31+n+31+30+31+30+31+31+30+31+c;}
else if(b==12){
m=31+n+31+30+31+30+31+31+30+31+30+c;}
printf("%d",m);
putchar('\n');
}
return 0;
}
