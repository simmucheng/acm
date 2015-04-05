#include<stdio.h>
#include<string.h>
int main()
{
    char s[110000],p;
    char q[28],k[28];
    int T,i,n,t,m,j,x,y;
    scanf("%d",&T);
    while(T--)
    {
        t=0;
        scanf("%s",&q);
        scanf("%s",&s);
        for(i=0;i<strlen(q);i++)
         k[q[i]-'a']='a'+i;
        m=strlen(s);
        n=m;
        if(m%2==1)
        m=m/2+1;
        else m=m/2;
        p=k[s[0]-'a'];
            for(i=m;i<n+1;i++)
            {
            if(p==s[i]){ printf("%c\n",s[i]);
                for(j=i+1;j<n+1;j++)
                if(s[j]!=k[s[j-i]-'a']){t=1;break;}
                else continue;
                if(t==0){y=i;break;}
                       }
            else y=i;
            }
            printf("%d\n",y);
        for(i=0;i<y;i++)
           printf("%c",s[i]);
        for(i=0;i<y;i++)
            printf("%c",k[s[i]-'a']);
        putchar('\n');
            }
    return 0;
}
