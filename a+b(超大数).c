#include<stdio.h>
#include<string.h>
char a[1010],s[1010];
int main()
{
    int b,i,j,m,n,z,y,x=0,v,p;
    char q;
    scanf("%d",&v);
    for(x=1;x<=v;x++)
    {
        scanf("%s",&a);
        scanf("%s",&s);
    m=strlen(a);
    n=strlen(s);
    b=0;
    z=n;
    y=m;
    printf("Case %d:\n",x);
    printf("%s + %s = ",a,s);
    if(m==n)
    {
        p=(a[0]-'0'+s[0]-'0')/10;
        if(p==1)printf("%d",p);
    }
  if(m>n){
    for(i=y;i>y-z;i--)
    {
        q=(a[i-1]-'0'+s[n-1]-'0'+b)%10+'0';
        b=(a[i-1]-'0'+s[n-1]-'0'+b)/10;
        a[i-1]=q;
        n--;
    }

    if(b==1){a[i-1]=a[i-1]-'0'+b+'0';}
    for(i=0;i<m;i++)
    {printf("%c",a[i]);}
    ;
    }
    else {
    for(i=z;i>z-y;i--)
    {
        q=(a[m-1]-'0'+s[i-1]-'0'+b)%10+'0';
        b=(a[m-1]-'0'+s[i-1]-'0'+b)/10;
        s[i-1]=q;
        m--;
    }
     if(b==1){s[i-1]=s[i-1]-'0'+b+'0';}
    for(i=0;i<n;i++)printf("%c",s[i]);
    }
     if(x<v){putchar('\n');putchar('\n');}
     else putchar('\n');}

    return 0;
}
