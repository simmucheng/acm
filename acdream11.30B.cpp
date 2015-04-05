#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int s[50010];
int e[50010];
vector<int>q[50010];
int main()
{
    int m,n,i,j;
    int mark;
    int a,b;
    while(cin>>n)
    {
        m=n;
       // memset(s,0,sizeof(s));
       for(i=1;i<=m;i++)
       s[i]=0;
        n--;
        int num=0;
        int mark;
        int ma=0;
        while(n--)
        {
            scanf("%d%d",&a,&b);
            q[a].push_back(b);
            q[b].push_back(a);
            s[a]++;
            if(s[a]==1)mark=a;
            s[b]++;
            if(s[b]==1)mark=b;
        }
            /*if(e[m]==mark){mi=min(mi,e[m]);}
            else
              {
                for(int l=m;l>=1;l++)
                 {
                   if(l==i)continue;
                   if(e[l]==mark-2){w=1;mi=min(mi,mark-1);break;}
                   else if(e[l]==mark){w=1;mi=min(mi,mark);break;}
                 }
                if(w==0)mi=min(mi,mark-1);
              }*/
             // cout<<"mi = "<<mi<<endl;
        }
         printf("%d\n",m-mi-1);
    }
    return 0;
}
