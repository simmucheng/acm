#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int i,j,m,n;
    int s[100];
    int w[3];
    while(cin>>n)
    {
        memset(w,0,sizeof(w));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            if(i%3==1)w[0]+=s[i];
            else if(i%3==2)w[1]+=s[i];
            else w[2]+=s[i];
        }
        int mark;
        int ma;
        if(w[0]>w[1]){ma=w[0],mark=0;}
        else {ma=w[1];mark=1;}
        if(ma<w[2]){mark=2;}
        if(mark==0)cout<<"chest"<<endl;
        else if(mark==1)cout<<"biceps"<<endl;
        else cout<<"back"<<endl;
    }
    return 0;
}
