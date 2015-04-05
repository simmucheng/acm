#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 100000
int s[N];
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main ()
{
    int y,z,i,j,k,m,q,p=0;
    scanf("%d",&y);
    while(1)
    {
        if(p>=y)break;
        p++;
        scanf("%d",&z);
       for(j=0;j<=z-1;j++)
           scanf("%ld",&s[j]);
      qsort(s,z,sizeof(s[0]),cmp);
    printf("%ld\n",s[(z-1)/2]);
    }
    return 0;
}
