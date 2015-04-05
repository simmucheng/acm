#include<stdio.h>
__int64 a,l,i;
__int64 s[100009];
__int64 n,q,con,k,p,o;
void dfs(a)
{
    q=0;
    for(l=a+1;l<n-1;l++)
    {
        q=q+s[l];
        if(q<0||o-q<0)continue;
        else {o=o-s[l];a=l;dfs(l);con++;}
    }
    con=con%1000000009;
}
int main()
{
    __int64 j,m,a,b,c;
    while(scanf("%I64d",&n)!=EOF)
    {
        k=0;
        p=0;
        con=0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&s[i]);
            k=k+s[i];
        }
        for(i=0;i<n;i++)
        {
            p=p+s[i];
            if(p<0||k-p<0){continue;}
            else {printf("%d\n",i+1);o=k-p;con++;dfs(i);}
        }
        printf("%I64d\n",con%1000000009);
    }
    return 0;
}
