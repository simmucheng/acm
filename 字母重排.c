#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
char w[2000][10],s[2000][10];
int cmp_char(const void *a,const void *b)
{
    return *(char*)a-*(char*)b;
}
int main()
{
    n=0;
    int i;
    while(1)
    {
        scanf("%s",w[n]);
        if(w[n][0]=='*')break;
        n++;
    }
    for(i=0;i<n;i++)
    {
        strcpy(s[i],w[i]);
        qsort(w[i],strlen(w[i]),sizeof(char),cmp_char);
    }
    int answer,m=0;
    char a[10];
    while(scanf("%s",a)==1)
    {
        qsort(a,strlen(a),sizeof(char),cmp_char);
         //puts(a);
        for(i=0;i<n;i++)
        {
        answer=strcmp(w[i],a);
        //puts(w[i]);
        //putchar('\n');
        //puts(a);
        //printf("%d",answer);
        if(answer==0)
        {
            m=1;
            puts(s[i]);
        }
        }
    if(m==0)printf("this is a pity\n");
   // puts(a);
    //putchar('\n');
    //puts(w);

    }
      return 0;
}
