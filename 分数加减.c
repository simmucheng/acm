#include<stdio.h>
#include<math.h>
int main ()
{


    int a,b,c,d,n,m,x,y;
    int e,j,k,l,z,h,i,k1,z1,p1;
    int e1,e2;
    scanf("%d\n",&h);
    for(j=1;j<=h;j++){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a>10000||b>10000||c>10000||d>10000)break;
    m=a*d;
    n=c*b;
    l=b*d;
    e=m+n;
    e1=e;
    e2=l;
    p1=m-n;
    i=l;
    if((m+n)%l==0){
        x=(a*d+c*b)/(b*d);
        printf("%d ",x);
    }

    else {
        int x1,x2,x3;
        if(e<=l){
            x1=l;
        x2=e;
        }

   else{ x1=e;
    x2=l;}
    while(x2){
        x3=x1%x2;
        if(x3==0)break;
        x1=x2;
        x2=x3;

    }
    x2=abs(x2);
    k=(m+n)/x2;
    z=i/x2;
    if(z<0){
    z=abs(z);
    k=-k;
    }
     printf("%d/%d ",k,z);
}
    if((m-n)%(b*d)==0){
        y=(a*d-c*b)/(b*d);
        printf("%d\n",y);}
    else {
        int p2,p3;
        if((m-n)<=l){
            p1=e2;
        p2=(m-n);
        }
        while(p2){
        p3=p1%p2;
        if(p3==0)break;
        p1=p2;
        p2=p3;

    }
    k1=(m-n)/p2;
    if(p2<0){
    p2=abs(p2);
    k1=-k1;
    }
    z1=i/p2;
    if(z1<0){
    z1=abs(z1);
    k1=-k1;
    }
    printf("%d/%d\n",k1,z1);

}
}

        return 0;
    }


