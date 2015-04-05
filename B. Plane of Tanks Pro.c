#include<stdio.h>
#include<string.h>
int mian()
{
    char s[1000][10];
    int a[1000];
    int n,m,i,j;
    long long sum;
    float k;
    while(scanf("%d",&n)==1)
    {
        i=-1;
        m=n;
        while(n--)
        {
            i++;
            scanf("%s",&s[i]);
            scanf("%d",&a[i]);
            if(n==m-1)continue;
            else
            {
                for(j=0;j<=i;j++)
                if(strcmp(s[i],s[j])>0){a[j]=a[j]>a[i]?a[j]:a[i];i--;}
            }
            for(j=0;j<=i;j++)
                sum=a[j]+sum;
            for(j=0;j<=i;j++)
            {
               k=a[j]*1.0/sum;
               if(k<0.5)printf("noob\n");
               else if(k>=0.5&&k<0.8)printf("random\n");
               else if(k>=0.8&&k<0.9)printf("average\n");
               else if(k>=0.9&&k<0.99)printf("hardcore\n");
               else printf("pro\n");
            }
        }
    }
    return 0;
}
