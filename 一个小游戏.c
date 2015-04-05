#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,m,n,x,s[1000],k,p,q,l;
    i=0;
    scanf("%d",&x)(´Ë³ÌÐò´íÎó);
    while(x--)
    {
        memset(s,0,sizeof(s));
        scanf("%d%d",&m,&n);
    k=0;
    i=0;
    l=1;
    while(i<m)
    {
            j=0;
            while(j<n)
            {
                if(l==m)l=-1;
                if(s[l++]==0)j++;
            }
            s[l]=1;
            printf("%d ",l);
            i++;
            if(i>=m)break;
            j=0;
            l++;
            while(j<n)
            {
                if(l==0)l=m+1;
                if(s[l--]==0)j++;
            }
            s[l]=1;
            printf("%d ",l);
            i++;
            l--;
        }
     printf("%d\n",l);
    }
     return 0;
}
