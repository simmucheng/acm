#include<stdio.h>
int main()
{
    long ju(int a0,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,long k);
    long n,y;
    int m;
    int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9;
    while(scanf("%ld%d",&y,&m)==2){
    scanf("%d%d%d%d%d%d%d%d%d%d",&x0,&x1,&x2,&x3,&x4,&x5,&x6,&x7,&x8,&x9);
    n=ju(x0,x1,x2,x3,x4,x5,x6,x7,x8,x9,y);
    printf("%ld\n",n%m);}
}
long ju(int a0,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,long k)
{
    long z,i,j,f[10],d;
    f[0]=a0;
    f[1]=a1;
    f[2]=a2;
    f[3]=a3;
    f[4]=a4;
    f[5]=a5;
    f[6]=a6;
    f[7]=a7;
    f[8]=a8;
    f[9]=a9;
    if(k<=9)z=k;
    else {
            d=a0*a0+a1;
            for(i=1;i<=(k-10)/2;i++)
    {
        f[0]=f[0]*d+f[1];
        f[1]=f[1]*d+f[2];
        f[2]=f[2]*d+f[3];
        f[3]=f[3]*d+f[4];
        f[4]=f[4]*d+f[5];
        f[5]=f[5]*d+f[6];
        f[6]=f[6]*d+f[7];
        f[7]=f[7]*d+f[8];
        f[8]=f[8]*d+f[9];
        f[9]=f[9]*d;
    }
    if((k-10)%2==1)
    {
        d=a0;
        f[0]=f[0]*d+f[1];
        f[1]=f[1]*d+f[2];
        f[2]=f[2]*d+f[3];
        f[3]=f[3]*d+f[4];
        f[4]=f[4]*d+f[5];
        f[5]=f[5]*d+f[6];
        f[6]=f[6]*d+f[7];
        f[7]=f[7]*d+f[8];
        f[8]=f[8]*d+f[9];
        f[9]=f[9]*d;
    }
    z=9*f[0]+8*f[1]+7*f[2]+6*f[3]+5*f[4]+4*f[5]+3*f[6]+2*f[7]+1*f[8];
    }
    return (z);
}
