#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Person
{
    int w;
    int sp,len;
    int pre,before;
}Mice[1000];
int cmp(const void*x,const void*y)
{

    return (*(struct Person*)x).w-(*(struct Person*)y).w;
}
int main()
{
    int i,j,c,d,m,n,t;
    int a[1001],s[1001];
    i=0;
    j=0;
    while(scanf("%d%d",&Mice[i].w,&Mice[i].sp))
    {
     Mice[i].pre=i;
     i++;
    }
    printf("%d %d\n",Mice[i].w,Mice[i].sp);
    t=i;
    d=0;
    c=0;
    qsort(Mice,1000,sizeof(struct Person),cmp);
    for(i=0;i<t;i++)
    {
        for(j=0;j<i;j++)
        {
            if(Mice[i].sp<Mice[j].sp)
           {
               c=c>Mice[j].len?c:Mice[j].len;
               Mice[i].before=Mice[j].pre;
           }
        }
        Mice[i].len=c+1;
    }
    for(i=0;i<t;i++)
    {
        d=d>Mice[i].len?d:Mice[i].len;
    }
      printf("%d\n",d);
      return 0;
}
