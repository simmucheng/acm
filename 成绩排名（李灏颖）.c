#include<stdio.h>
struct student
{
    int a;
    int b;
};
int main()
{
    struct student stu[50]={0};
    struct student n;
    int i,j,k,t;

    for(i=0;i<=49;i++)
    {
        scanf("%d %d",&stu[i].a,&stu[i].b);
    }
    for(j=0;j<=49;j++)
    {
        for(i=0;i<=48-j;i++)
        {
            k=i;
            t=i+1;
            if(stu[k].b<stu[t].b)
          {
            n=stu[k];
            stu[k]=stu[t];
            stu[t]=n;
          }
    }
    }
   for(i=0;i<=49;i++)
    {
        printf("%d %d\n",stu[i].a,stu[i].b);
    }
    return 0;
}
