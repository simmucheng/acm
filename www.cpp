#include<iostream>
#include<cstdio>
using namespace std;
int m,n,i,j,k,t,x;
char p[2000000];
int next[2000000];
void getNext(int *next)
{
    int i,j,k;
    next[0]=-1;
    j=0;
    k=-1;
    while(j<t)
    {
        if(k==-1||p[j]==p[k])
        {
            k++;
            j++;
            next[j]=k;
        }
        else
        k=next[k];
    }
}
int main(){
    k=0;
  while(1)
  {
      k++;
    scanf("%d",&t);
    if(t==0)
      break;
    scanf("%s",p);
     printf("Test case #%d\n",k);
     getNext(next);
     for(i=0;i<t;i++)
        printf("%d ",next[i]);
    cout<<endl;
    for(i=2;i<=t;i++)
    if(next[i]!=0&&i%(i-next[i])==0)
    {
        x=i/(i-next[i]);
      printf("%d %d\n",i,x);
    }
      printf("\n");
  }
    return 0;
}