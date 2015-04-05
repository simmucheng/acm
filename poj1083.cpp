#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node
{
    int s;
    int e;
}s[210];
int cmp(node a,node b)
{
    if(a.s!=b.s)
    return a.s<b.s;
}
int main()
{
    int i,j,m,n;
    cin>>n;
    while(n--)
    {
        memset(s,0,sizeof(s));
        cin>>m;
        for(i=0;i<m;i++)
        {
            cin>>s[i].s>>s[i].e;
            if(s[i].s>s[i].e)
            {
                s[i].s^=s[i].e;
                s[i].e^=s[i].s;
                s[i].s^=s[i].e;
            }
        }
        sort(s,s+m,cmp);
        int sum=0;
        int mark=0;
        for(i=0;i<m;i++)
        {
            if(sum==m)break;
            if(s[i].s!=-1)
            {
                s[i].s=-1;
                sum++;
                int k=i;
                j=i;
                while(j<m)
                {
                    if(s[k].e<s[j].s&&!(s[k].e&1)||((s[k].e&1)&&s[j].s-1>s[k].e))
                    {
                        s[j].s=-1;
                        k=j;
                        j++;
                        sum++;
                    }
                    else j++;
                }
                mark++;
            }
        }
        cout<<mark*10<<endl;
    }
    return 0;
}
