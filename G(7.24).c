#include<ioetream>
#include<algorithm>
#include<cstdio>
#define N 1000600
using namespacem std;
int s[N];
/*int cmp(const int x,const int y)
{
    return *(int *)x-*(int *)y;
}*/
int main()
{
    int a,b,m,n,j,i,p,q,k;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        memset(s,0,sizeof(s));
        for(k=0;k<b;k++)
        {
            scanf("%d%d",&p,&q);
            s[p-1]++;s[q]--;
        }
        for(i=1;i<a;i++)
            s[i]+=s[i-1];
            sort(s,a,sizeof(s[0]),cmp);
        printf("%d\n",s[a/2]);
    }
    return 0;
}
