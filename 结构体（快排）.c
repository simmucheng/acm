#include<stdio.h>
#include<stdlib.h>
typedef struct {
int pi;
int ci;
}cho1;
cho1 cho[100000];
int cmp(const void *p,const void *q){
cho1 *a=(cho1 *)p;
cho1 *b=(cho1 *)q;
return a->pi-b->pi;
}
int main(){
int i,n,b;
while(scanf("%d %d",&n,&b)==2){
for(i=1;i<=n;i++)scanf("%d %d",&cho[i].pi,&cho[i].ci);
qsort(cho+1,n,sizeof(cho[0]),cmp);
for(i=1;i<=n;i++)printf("%d %d\n",cho[i].pi,cho[i].ci);
}
return 0;
}
