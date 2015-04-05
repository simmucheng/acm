#include<iostream>
using namespace std;
int s[100100];
int main()
{
    int i,j,m,n,k;
    while(cin>>n>>k)
    {
        int con=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
            if(s[i]==i){s[i]=-1;con++;}
        }
        int co=0;
        for(i=0;i<n;i++)
        {
            if(s[s[i]]==i){co++;s[i]=-1;s[s[i]]=-1;}
        }
        if(k<=co)printf("%d\n",con+k*2);
        else
        {

        }
    }
}
