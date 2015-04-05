#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int s[100010];
    int i,j,m,n;
    while(cin>>n)
    {
        //memset(s,,0,sizeof(s));
        for(i=0;i<n;i++)
        scanf("%d",&s[i]);
        int mm=0xfffffff;
        int num=0;
        for(i=n-1;i>=0;i--)
        {
            if(mm>s[i])mm=s[i];
            else {num=i+1;break;}
        }
        printf("%d\n",num);
    }
    return 0;
}
