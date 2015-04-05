#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;
char s[2][100];
map<string,int> ma;
map<string,string>fa;
map<string,int> mark;
map<string,int>kk;
string h;
string dfs(string nn)
{
    if(fa[nn]==h){ma[nn]=1;return nn;}
    fa[nn]=dfs(fa[nn]);
    ma[nn]=ma[fa[nn]]+1;
    return fa[nn];
}
int abb(int aa)
{
    if(aa<0)return -aa;
    return aa;
}
int main()
{
    int i,j,m,n;
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for(i=2;i<=x;i++)
        {
            scanf("%s%s",s[0],s[1]);
            fa[s[0]]=s[1];
            //cout<<s[0]<<endl;
            mark[s[1]]=1;
            kk[s[0]]=1;
        }
        //cout<<kk.size()<<endl;
        map<string,int>::iterator it;
        for(it=kk.begin();it!=kk.end();it++)
        {
            cout<<it->first<<' '<<it->second<<endl;
            if(it->second!=1)
            {
                cout<<"rrrr"<<endl;
                        h=it->first;
                        break;
            }
        }
        for(it=mark.begin();it!=mark.end();it++)
        {
            if(it->second!=1)
            {
                    cout<<it->first<<endl;
                    if(ma[it->first]==0)
                    dfs(it->first);
            }
        }
        memset(s,0,sizeof(s));
        while(y--)
        {

            scanf("%s%s",s[0],s[1]);
            if(fa[s[0]]==fa[s[1]])
                printf("%d",abb(ma[s[1]]-ma[s[0]]));
            else
            {
                printf("%d\n",ma[s[0]]+1);
            }
        }
    }
    return 0;
}

