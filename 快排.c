#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int s[100];
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
     int c,i;
    scanf("%d",&c);
    for(i=0;i<c;i++)
    {
        scanf("%d",&s[i]);
    }
    qsort(&s,c,sizeof(s[0]),cmp);
    for(i=0;i<c;i++)
        printf("%d ",s[i]);
        return 0;
}
